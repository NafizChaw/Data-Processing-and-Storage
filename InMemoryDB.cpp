#include "InMemoryDB.h"

InMemoryDB::InMemoryDB() : transaction_in_progress(false) {}

void InMemoryDB::begin_transaction() {
    if (transaction_in_progress) {
        throw std::runtime_error("A transaction is already in progress.");
    }
    transaction_data.clear();
    transaction_in_progress = true;
}

void InMemoryDB::put(const std::string& key, int value) {
    if (!transaction_in_progress) {
        throw std::runtime_error("No transaction in progress.");
    }
    transaction_data[key] = value;
}

int InMemoryDB::get(const std::string& key) {
    if (transaction_in_progress && transaction_data.find(key) != transaction_data.end()) {
        return transaction_data[key];
    }
    if (data.find(key) != data.end()) {
        return data[key];
    }
    return -1;
}

void InMemoryDB::commit() {
    if (!transaction_in_progress) {
        throw std::runtime_error("No transaction in progress.");
    }
    data.insert(transaction_data.begin(), transaction_data.end());
    transaction_in_progress = false;
}

void InMemoryDB::rollback() {
    if (!transaction_in_progress) {
        throw std::runtime_error("No transaction in progress.");
    }
    transaction_in_progress = false;
    transaction_data.clear();
}
