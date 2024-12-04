#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <tuple>

int main()
{
	std::vector<std::string> letters;

	std::copy(std::istream_iterator<std::string>{std::cin}, std::istream_iterator<std::string>{}, std::back_inserter(letters));

	// it's a non-empty grid, all rows have the same number of letters
	const int ROWS = letters.size();
	const int COLUMNS = letters[0].size();

	using Coordinates = std::tuple<int, int>;

	std::vector<Coordinates> relevantCoords;

	// Find all As in the grid not too close to the border
	for (int r=1 ; r<ROWS-1 ; r++) {
		for (int c=1 ; c<COLUMNS-1 ; c++) {
			if (letters[r][c] == 'A')
				relevantCoords.emplace_back(r, c);
		}
	}
	std::cout << "number of A in grid: " << relevantCoords.size() << std::endl;

	// And then we look for the other letters around
	long found = 0;
	for (auto&& [rx, cx] : relevantCoords) {
		found += ((letters[rx-1][cx-1] == 'M' && letters[rx+1][cx+1] == 'S') ||
		          (letters[rx-1][cx-1] == 'S' && letters[rx+1][cx+1] == 'M')) &&
		         ((letters[rx+1][cx-1] == 'M' && letters[rx-1][cx+1] == 'S') ||
		          (letters[rx+1][cx-1] == 'S' && letters[rx-1][cx+1] == 'M'));
	}


	std::cout << found << std::endl;
}
