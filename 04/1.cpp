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
	long found = 0;

	// Find all Xs in the grid
	for (int r=0 ; r<ROWS ; r++) {
		for (int c=0 ; c<COLUMNS ; c++) {
			if (letters[r][c] == 'X')
				relevantCoords.emplace_back(r, c);
		}
	}
	std::cout << "number of X in grid: " << relevantCoords.size() << std::endl;

	// And then we look for the other letters adjecent to the prefix we've
	// found
	for (auto&& [rx, cx] : relevantCoords) {
		for (auto&& [dr,dc] : std::initializer_list<Coordinates>{{-1,-1}, {-1,0}, {-1,+1}, {0,-1}, {0,+1}, {+1,-1}, {+1,0}, {+1,+1}}) {
			int r = rx;
			int c = cx;
			for (char target : {'M', 'A', 'S'}) {
				r += dr;
				c += dc;
				if (r < 0 || r >= ROWS || c < 0 || c >= COLUMNS || letters[r][c] != target) {
					goto next;
				}
			}
			found++;
next:
			;
		}
	}


	std::cout << found << std::endl;
}
