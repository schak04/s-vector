# Testing Notes

- Write tests for the public behaviour, not the implementation.
- Keep each test focused on one behaviour.
- Use `assert()` to verify the expected state after each operation.
- Test both the normal case and important edge cases.
- Verify data integrity after operations like resizing.
- Compile with warnings and sanitisers.
- If all assertions pass, print a simple success message.
