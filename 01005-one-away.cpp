#include <iostream>
#include <string>

using namespace std;

string checkModification(string str1, string str2, int size_diff) {
	int s1 = 0, s2 = 0, mods = 0;

	while (s2 <= str2.size()) {
		if (str1[s1] == str2[s2]) {
			s1++;
			s2++;
			continue;
		}
		else if (size_diff > 0) {
			s1++;
			mods++;
		}
		else {
			s1++;
			s2++;
			mods++;
		}
	}
	return mods > 1 ? "False" : "True";
}

int main(int argc, char * argv[]) {
	if (argc != 3) {
		cout << "Arguments: Expected 2. Found " << argc - 1 << endl;
		return 1;
	}

	string s1 = argv[1];
	string s2 = argv[2];
	string ret = "";

	int diff = s1.size() - s2.size();
	if (diff == 0) {
		ret = checkModification(s1, s2, 0);
	}
	else if (diff == 1) {
		ret = checkModification(s1, s2, 1);
	}
	else if (diff == -1) {
		ret = checkModification(s2, s1, 1);
	}
	else {
		ret = "False";
	}

	cout << ret << endl;

	return 0;
}
