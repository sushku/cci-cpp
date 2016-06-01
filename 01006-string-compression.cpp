#include <iostream>
#include <string>

using namespace std;

string compressString(string str) {
    int s = str.size();
    string retstr = "";
    char prev = '\0';
    int count = 0;

    for (int i = 0; i < s; i++) {
        if (str[i] != prev) {
            if (count != 0) {
                retstr += (char)(count + 48);
            }
            retstr += str[i];
            count = 1;
            prev = str[i];
        }
        else {
            count ++;
        }
    }
    retstr += (char)(count + 48);
    if (retstr.size() < s)
        return retstr;
    else
        return str;
}

int main(int argc, char * argv[]) {
    if (argc != 2) {
        cout << "Arguments: Expected 1. Found " << argc - 1 << endl;
        return 1;
    }

    cout << compressString(argv[1]) << endl;
    return 0;
}
