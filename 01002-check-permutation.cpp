#include <iostream>
#include <string>

using namespace std;

string checkPermutation(string str1, string str2) {
	if(str1.size() != str2.size()) {
		return "Not a permutation";
	}

	sort(str1.begin(), str1.end());
	sort(str2.begin(), str2.end());

	if(str1 != str2)
		return "Not a permutation";

	return "Permutation";
}

int main(int argc, char * argv[]) {
	if(argc != 3) {
		cout << "Arguments: Expected 2. Found " << argc - 1 << endl;
		return 1;
	}

	cout << checkPermutation(argv[1], argv[2]) << endl;
	return 0;
}
