
// SPDX-License-Identifier: MIT
pragma solidity >=0.5.0 <0.9.0;

contract StudentData {
    // Structure to represent a student
    struct Student {
        uint id;
        string name;
        uint age;
        string course;
    }

    // Array to store all students
    Student[] public students;

    // Function to add a new student
    function addStudent(uint _id, string memory _name, uint _age, string memory _course) public {
        require(_age > 5, "Age must be greater than 5");
        students.push(Student(_id, _name, _age, _course));
    }

    // Fallback function to handle unexpected calls or Ether transfers
    fallback() external payable {
        // Logging a message (can be viewed with debugging tools)
        // Accept Ether and provide a simple response
        if (msg.value > 0) {
            // Handle the incoming Ether (e.g., store or log the event)
            // Here, we just accept the Ether, so no state change happens
        } else {
            revert("Fallback function called without sending Ether");
        }
    }

    // Function to get the number of students
    function getNumberOfStudents() public view returns (uint) {
        return students.length;
    }
}
