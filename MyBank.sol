
// SPDX-License-Identifier: MIT
pragma solidity ^0.8.0;

contract MyBank {

    mapping(address => uint) public uaccount;
    mapping(address => bool) public uexist;

    function create_account(address user) public payable returns (string memory) {
        if (uexist[msg.sender] == true) {
            return "User already present";
        } else {
            uexist[user] = true;
            uaccount[user] = 0;
            return "User created successfully";
        }
    }

    function add_amount(address user, uint amount) public payable returns (string memory) {
        if (uexist[user] != true) {
            return "User not present";
        } else {
            uaccount[user] += amount;
            return "Amount credited successfully";
        }
    }

    function draw_amount(address user, uint amount) public payable returns (string memory) {
        if (uexist[user] != true) {
            return "User not present";
        } else if (uaccount[user] < amount) {
            return "Not enough balance to withdraw";
        } else {
            uaccount[user] -= amount;
            return "Amount withdrawn successfully";
        }
    }

    function balance(address user) public view returns (uint) {
        return uaccount[user];
    }
}
