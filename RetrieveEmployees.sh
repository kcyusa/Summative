#!/bin/bash

FILE="employeeDataStorageBash.txt"

if [[ ! -f "$FILE" ]]; then
    echo "No employee records found."
    exit 1
fi

echo "Employee Records:"
cat "$FILE"
