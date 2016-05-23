#include <iostream>
#include <string>

using namespace std;

bool palindromePerm(string str) {
	int* charfreq = new int[26];
	int oddchars = 0;

	for(int j = 0; j < 26; j++) {
		charfreq[j] = 0;
	}

	for(int i = 0; i < str.size(); i++) {
		if((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z')) {
			charfreq[tolower(str[i]) - 'a'] += 1;
		}
	}
	for(int k = 0; k < 26; k++) {
		if(charfreq[k] % 2 != 0) {
			oddchars += 1;
		}
		if(oddchars > 1) {
			return false;
		}
	}
	return true;
}

int main(int argc, char * argv[]) {
	if(argc != 2) {
		cout << "Arguments: Expected 1. Found " << endl;
		return 1;
	}

	cout << (palindromePerm(argv[1]) ? "True" : "False") << endl;
	return 0;
}
