#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

string checkIfUnique(string str) {
	unordered_map<char, int> charmap;
	unordered_map<char, int>::const_iterator it;

	for(int i = 0; i < str.size(); i++) {
		charmap[str[i]] += 1;
	}

	/*for(it = charmap.begin(); it != charmap.end(); it++) {
		if(it->second > 1)
			return "Not unique";
	}*/

	for(const auto &rec : charmap) {
		if(rec.second > 1)
			return "Not unique";
	}
	return "Unique";
}

string mergeSort(string str) {
	string ret_str = "";
	return ret_str;
}

string checkIfUniqueAlt(string str) {
	//str = mergeSort(str);
	sort(str.begin(), str.end());
	char prev;
	for(int i = 0; i < str.size(); i++) {
		if(prev == str[i])
			return "Not unique";
		prev = str[i];
	}
	return "Unique";
}

int main(int argc, char * argv[]) {
	if(argc != 2) {
		cout << "Arguments: Expected 1. Found " << argc - 1 << endl;
		return 1;
	}
	string inpstr = argv[1];

	//cout << checkIfUnique(inpstr) << endl;;
	cout << checkIfUniqueAlt(inpstr) << endl;

	return 0;
}
