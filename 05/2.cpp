#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <sstream>

int main()
{
	std::unordered_map<int, std::vector<int>> rules;

	std::string s;
	for (std::getline(std::cin, s) ; std::cin && !s.empty() ; std::getline(std::cin, s)) {
		int before, after;
		char separator;
		std::istringstream is{s};
		is >> before >> separator >> after;

		rules[after].push_back(before);
	}

	long sum = 0;

	// what's left in the input are the updates
	for (std::getline(std::cin, s) ; std::cin && !s.empty() ; std::getline(std::cin, s)) {
		bool invalid = false;
		std::istringstream is{s};
		int page;
		char comma;
		is >> page >> comma;
		std::vector<int> firstPages = {page};
		while (is) {
			is >> page;
			for (auto it = firstPages.begin() ; it != firstPages.end() && !invalid ; ++it) {
				const auto& shouldBeBefore = rules[*it];
				if (std::find(shouldBeBefore.begin(), shouldBeBefore.end(), page) != shouldBeBefore.end())
					invalid = true;
			}
			firstPages.push_back(page);
			is >> comma;
		}

		if (invalid) {
			std::cout << "\tUpdate ";
			for (auto p : firstPages) {
				std::cout << p << " ";
			}
			std::cout << "is invalid, fixing..." << "\n";
			std::sort(firstPages.begin(), firstPages.end(),
				[&rules](int p1, int p2) {
					return std::find(rules[p2].begin(), rules[p2].end(), p1) != rules[p2].end();
				});

			int middlePage = firstPages[firstPages.size() / 2];
			std::cout << "Update ";
			for (auto p : firstPages) {
				std::cout << p << " ";
			}
			std::cout << ", adding " << middlePage << "\n";
			sum += middlePage;
		}
	}

	std::cout << sum << std::endl;
}
