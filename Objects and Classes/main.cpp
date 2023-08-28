#include <iostream>
#include <sstream>
#include <vector>
#include <string>

class WordShifter {
	std::vector<std::string> words;

public:

	WordShifter(const std::vector<std::string> & words_) : words(words_) {}

	void shift(size_t times);

	const std::vector<std::string>& getShiftedSentence();
};

void WordShifter::shift(size_t times) {
	while (times)
	{
		std::string currWord = words[words.size() - 1];
		words.pop_back();
		words.insert(words.begin(), currWord);
		times--;
	}	
}

const std::vector<std::string>& WordShifter::getShiftedSentence() {	
	return words;
}



int main() {
	std::vector<std::string> words;

	std::string buffer;
	getline(std::cin, buffer);
	std::istringstream iss(buffer);
	std::string word;
	while (iss >> word)
	{
		words.push_back(word);
	}

	int shifts;
	std::cin >> shifts;

	WordShifter shifter(words);

	shifter.shift(shifts);

	const std::vector<std::string>& shiftedSentence = shifter.getShiftedSentence();

	for (auto word : shiftedSentence)
	{
		std::cout << word << std::endl;
	}

	return 0;

}