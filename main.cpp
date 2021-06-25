/*
 * main.cpp
 *
 *  Created on: Jun 25, 2021
 *      Author: d-w-h
 */

#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>

std::string get_max_palindrome2(std::string s) {

	std::string result = s;

	int size_string = s.length();
	int num_dummy_elements = size_string - 1;

	//Base cases
	if(size_string == 0) { return ""; }
	if(size_string == 1) { return result; }
	if(size_string == 2) {
		if(result[0] == result[1]) { return result;	}
		else { return result.substr(0, 1); }
	}

	int total_num_elements = size_string + num_dummy_elements;
	std::string dummy_string;
	int index = 0;
	int index_string = 0;
	while(index < total_num_elements) {
		dummy_string = dummy_string + s[index_string];
		index++;
		index_string++;
		dummy_string = dummy_string + '@';
		index++;
	}

	//Compute max palindrome
	int size_palindrome = 1;
	int left_index;
	int right_index;
	for(int i = 1; i < total_num_elements - 1; ++i) {
		int left_track = i - 1;
		int right_track = i + 1;
		int size_palindrome_loc = 1;
		while(dummy_string[left_track] == dummy_string[right_track] && left_track >= 0 && right_track <= total_num_elements) {
			size_palindrome_loc = size_palindrome_loc + 2;
			if(size_palindrome_loc > size_palindrome) {
				size_palindrome = size_palindrome_loc;
				left_index = left_track;
				right_index = right_track;
			}
			left_track--;
			if(left_track < 0) {left_track = 0;}
			right_track++;
			if(right_track >= total_num_elements) { right_track = total_num_elements; }
		}
	}

	//Construct palindrome
	std::string palindrome;
	for(int i = left_index; i <= right_index; ++i) {
		if(dummy_string[i] != '@') {
			palindrome = palindrome + dummy_string[i];
		}
	}

	return palindrome;
}

int main(int argc, char* argv[]) {

	std::string s = "xaabacxcabaaxcabaasdffhxxaabacxcghdabaaxcabaaxxcabaaxxaabacxcabaaxca";
	std::string max_palindrome = get_max_palindrome2(s);

	std::cout << "input string: " << s << std::endl;
	std::cout << "max palindrome: " << max_palindrome << std::endl;
	std::cout << "done" << std::endl;

	return 0;
}
