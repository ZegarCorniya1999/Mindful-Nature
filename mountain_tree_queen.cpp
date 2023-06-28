#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

// Global Variables
const string MINDFUL_NATURE = "Mindful Nature";

// Function Prototypes
int countVowels(string str);
void displayMindfulNature();
void displayMindfulNatureMenu();
void exploreMindfulNature();
void generateMindfulNatureImages();
int getRandomNumber(int min, int max);
void printMindfulNatureThoughts();
string removeWhitespace(string str);
void setMindfulNatureMood();

// Main Program
int main()
{
	// Set initial mindful nature mood
	setMindfulNatureMood();

	// Display mindful nature menu
	displayMindfulNatureMenu();

	// Get user input
	int input;
	cin >> input;

	while (input != 0)
	{
		switch (input)
		{
			case 1: displayMindfulNature(); break;
			case 2: exploreMindfulNature(); break;
			case 3: generateMindfulNatureImages(); break;
			case 4: printMindfulNatureThoughts(); break;
			default: cout << "Invalid selection. Please try again.\n";
		}

		// Get user input
		displayMindfulNatureMenu();
		cin >> input;
	}
	
	return 0;
}

// Function Definitions
int countVowels(string str)
{
	int count = 0;

	for (const char& c : str)
	{
		if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
			count++;
	}

	return count;
}

void displayMindfulNature()
{
	cout << "Welcome to " << MINDFUL_NATURE << "!\n";
}

void displayMindfulNatureMenu()
{
	cout << "\nSelect an option:\n";
	cout << "1. Display Mindful Nature\n";
	cout << "2. Explore Mindful Nature\n";
	cout << "3. Generate Mindful Nature Images\n";
	cout << "4. Print Mindful Nature Thoughts\n";
	cout << "0. Exit\n\n";
}

void exploreMindfulNature()
{
	cout << "Exploring " << MINDFUL_NATURE << "...\n\n";
	cout << "The beauty of nature is all around us. Take a moment to appreciate the wonders of the world.\n";
}

void generateMindfulNatureImages()
{
	int randomNumber;

	for (int i = 0; i < 10; i++)
	{
		randomNumber = getRandomNumber(1, 10);
		cout << "Generating image #" << randomNumber << "...\n";
	}

	cout << "Done!\n";
}

int getRandomNumber(int min, int max)
{
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
	return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

void printMindfulNatureThoughts()
{
	vector<string> thoughts = {
		"Embrace the beauty of nature.",
		"Pause and observe the perfection of the world around you.",
		"Live in the present moment.",
		"Take a moment to appreciate the wonders of the world.",
		"Allow yourself to become one with nature.",
		"Find peace and solace in the natural world.",
		"Let nature be your teacher.",
		"Be mindful and respect nature.",
		"Allow yourself to experience the wonders of nature.",
		"Find balance and harmony in nature.",
		"Be inspired by the beauty of nature."
	};

	map<int, string> thoughtVowelMap;

	for (const string& thought : thoughts)
	{
		// Count number of vowels
		int numVowels = countVowels(removeWhitespace(thought));

		thoughtVowelMap[numVowels] = thought;
	}

	cout << "Here are some mindful nature thoughts:\n";

	for (const auto& tvm : thoughtVowelMap)
		cout << tvm.second << endl;
}

string removeWhitespace(string str)
{
	str.erase(remove(str.begin(), str.end(), ' '), str.end());
	return str;
}

void setMindfulNatureMood()
{
	cout << "Setting a peaceful mood for " << MINDFUL_NATURE << "...\n";
	cout << "Take a deep breath and relax.\n";
}