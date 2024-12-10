#include <iostream>
#include "InMemoryDB.h"

int main() {
    InMemoryDB inmemoryDB;

    // Test 1: Get a non-existent key before any transaction
    std::cout << "Test 1: Get non-existent key A: " << inmemoryDB.get("A") << std::endl;

    // Test 2: Attempt to put data without a transaction
    try {
        inmemoryDB.put("A", 5);  // Should throw an error
    } catch (const std::exception& e) {
        std::cout << "Test 2: " << e.what() << std::endl;
    }

    // Test 3: Start a transaction and update values
    inmemoryDB.begin_transaction();
    inmemoryDB.put("A", 5);
    std::cout << "Test 3: Get key A before commit: " << inmemoryDB.get("A") << std::endl;

    // Test 4: Commit the transaction
    inmemoryDB.commit();
    std::cout << "Test 4: Get key A after commit: " << inmemoryDB.get("A") << std::endl;

    // Test 5: Rollback an uncommitted change
    inmemoryDB.begin_transaction();
    inmemoryDB.put("B", 10);
    inmemoryDB.rollback();
    std::cout << "Test 5: Get key B after rollback: " << inmemoryDB.get("B") << std::endl;

    return 0;
}
