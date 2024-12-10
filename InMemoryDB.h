#ifndef INMEMORYDB_H
#define INMEMORYDB_H

#include <unordered_map>
#include <string>
#include <stdexcept>

class InMemoryDB {
private:
    std::unordered_map<std::string, int> data;
    std::unordered_map<std::string, int> transaction_data;
    bool transaction_in_progress;

public:
    InMemoryDB();
    void begin_transaction();
    void put(const std::string& key, int value);
    int get(const std::string& key);
    void commit();
    void rollback();
};

#endif // INMEMORYDB_H
