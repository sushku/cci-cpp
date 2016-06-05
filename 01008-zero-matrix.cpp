#include <iostream>
#include <vector>

using namespace std;

void zeroiseRow(vector<vector<int> >& v, int i) {
    for (int j = 0; j < v[i].size(); j++) {
        v[i][j] = 0;
    }
}

void zeroiseCol(vector<vector<int> >& v, int j) {
    for (int i = 0; i < v.size(); i++) {
        v[i][j] = 0;
    }
}

void makeZero(vector<vector<int> >& v) {
    bool firstRowZero = false;
    bool firstColZero = false;
    for (int j = 0; j < v[0].size(); j++) {
        if (v[0][j] == 0) {
            firstRowZero = true;
            break;
        }
    }
    for (int i = 0; i < v.size(); i++) {
        if (v[i][0] == 0) {
            firstColZero = true;
            break;
        }
    }
    for (int i = 1; i < v.size(); i++) {
        for (int j = 1; j < v[i].size(); j++) {
            if (v[i][j] == 0) {
                v[i][0] = 0;
                v[0][j] = 0;
            }
        }
    }
    for (int i = 1; i < v.size(); i++) {
        if (v[i][0] == 0)
            zeroiseRow(v, i);
    }
    for (int j = 1; j < v[0].size(); j++) {
        if (v[0][j] == 0)
            zeroiseCol(v, j);
    }
    if (firstRowZero == true)
        zeroiseRow(v, 0);
    if (firstColZero == true)
        zeroiseCol(v, 0);
}

int main() {
    int r1[] = {0, 2, 3, 4};
    int r2[] = {1, 2, 3, 4};
    int r3[] = {1, 0, 3, 4};
    int r4[] = {1, 2, 3, 4};

    vector<int> v1(r1, r1 + sizeof(r1) / sizeof(r1[0]));
    vector<int> v2(r2, r2 + sizeof(r2) / sizeof(r2[0]));
    vector<int> v3(r3, r3 + sizeof(r3) / sizeof(r3[0]));
    vector<int> v4(r4, r4 + sizeof(r4) / sizeof(r4[0]));

    vector<vector<int> > v;

    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);
    v.push_back(v4);

    makeZero(v);

    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
