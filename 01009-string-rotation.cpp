#include <iostream>
#include <string>

using namespace std;

bool isSubString(string s, string sub) {
    if (s.find(sub) != string::npos)
        return true;
    else
        return false;
}

int main(int argc, char * argv[]) {
    if (argc != 3) {
        cout << "Arguments: Expected 2. Found " << argc - 1 << endl;
        return 1;
    }

    string s1 = argv[1];
    string s2 = argv[2];
    bool ret = true;

    if (s1.size() != s2.size())
        ret = false;
    else
        ret = isSubString(s1 + s1, s2);

    if (ret)
        cout << s1 << " is a rotation of " << s2 << endl;
    else
        cout << s1 << " is not a rotation of " << s2 << endl;

    return 0;
}
