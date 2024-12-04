#include <regex>
#include <iostream>
#include <iterator>

int main()
{
	std::regex r{R"(mul\((\d{1,3}),(\d{1,3})\)|do\(\)|don't\(\))"};

	std::string s;
	bool enabled = true;
	long long int sum = 0;
	for (std::getline(std::cin, s) ; std::cin ; std::getline(std::cin, s)) {
		auto mulBegin = std::sregex_iterator{s.begin(), s.end(), r};
		auto mulEnd = std::sregex_iterator{};

		for (auto i = mulBegin ; i != mulEnd ; ++i) {
			std::string matched = i->str();
			std::cout << "matched " << matched << std::endl;
			if (matched == "do()")
				enabled = true;
			else if (matched == "don't()")
				enabled = false;
			else if (enabled)
				sum += std::stoi((*i)[1]) * std::stoi((*i)[2]);
		}
	}

	std::cout << sum << std::endl;
}
