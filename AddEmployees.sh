#!/bin/bash

FILE="employeeDataStorageBash.txt"
> "$FILE"

for ((i = 1; i <= 5; i++)); do
    echo "Enter details for employee $i:"
    read -p "Email: " email
    read -p "Age: " age
    read -p "Salary: " salary
    
    echo "$email $age $salary" >> "$FILE"
done

echo "Employee details saved successfully."
