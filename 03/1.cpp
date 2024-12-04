#include <regex>
#include <iostream>
#include <iterator>

int main()
{
	std::regex r{"mul\\((\\d{1,3}),(\\d{1,3})\\)"};

	std::string s;
	long sum = 0;
	while (std::cin) {
		std::getline(std::cin, s);

		auto mulBegin = std::sregex_iterator{s.begin(), s.end(), r};
		auto mulEnd = std::sregex_iterator{};

		for (auto i = mulBegin ; i != mulEnd ; ++i) {
			sum += std::stoi((*i)[1]) * std::stoi((*i)[2]);
		}
	}

	std::cout << sum << std::endl;
}
