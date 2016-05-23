#include <iostream>
#include <string>

using namespace std;

void urlify(string& str, int n) {
	int j = str.size() - 1;
	for(int i = n - 1; i >= 0; i--) {
		if(str[i] == ' ') {
			str[j - 2] = '%';
			str[j - 1] = '2';
			str[j] = '0';
			j -= 3;
		}
		else {
			str[j] = str[i];
			j -= 1;
		}
	}
}

int main(int argc, char * argv[]) {
	if(argc != 3) {
		cout << "Arguments: Expected 2. Found " << argc - 1 << endl;
		return 1;
	}
	if (atoi(argv[2]) == 0) {
		cout << "Expected second argument to be an integer" << endl;
		return 1;
	}

	string inpstr = argv[1];
	urlify(inpstr, atoi(argv[2]));

	cout << inpstr << endl;
	return 0;
}
