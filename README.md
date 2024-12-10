# InMemoryDB

This is a simple implementation of an in-memory key-value database with support for transactions.

## How to Build and Run

1. Clone or download the repository.
2. Open the project in CLion.
3. Build the project by selecting **Build** -> **Build Project**.
4. Run the project by selecting **Run** -> **Run 'InMemoryDB'**.

### Functions Supported:
- `begin_transaction()`: Starts a new transaction.
- `put(key, value)`: Adds or updates a key-value pair. This works only within a transaction.
- `get(key)`: Retrieves the value for a given key, whether within or outside a transaction.
- `commit()`: Commits the transaction, applying changes to the main data.
- `rollback()`: Rolls back any changes made in the transaction.

## How to Modify for Future Assignments

- Consider adding support for multiple concurrent transactions.
- Improve error handling by throwing more specific exceptions.
- Enhance the `get()` method to provide better error messages or return `nullptr` instead of `-1` for non-existent keys.
