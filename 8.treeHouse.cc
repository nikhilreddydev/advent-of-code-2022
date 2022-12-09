#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main() {
    string line;
    vector<string> v;

    while(getline(cin, line))
        v.push_back(line);

    int cols = v[0].size(), rows = v.size();

    vector<vector<int>> scenicScore(rows, vector<int>(cols, 1));

    vector<vector<int>> posT(cols, vector<int>(10)), posL(rows, vector<int>(10));

    for(int i = 0; i < rows; ++i) {
        for(int j = 0; j < cols; ++j) {
            int height = v[i][j] - '0';

            // find top distance
            int ti{};
            for(int i = height; i < 10; ++i) {
                ti = max(ti, posT[j][i]);
            }

            int td = i - ti;

            // find left distance
            int lj{};
            for(int j = height; j < 10; ++j) {
                lj = max(lj, posL[i][j]);
            }

            int ld = j - lj;

            scenicScore[i][j] = td * ld;

            posT[j][height] = i;
            posL[i][height] = j;
        }
    }

    int res{};
    vector<vector<int>> posD(cols, vector<int>(10, rows - 1)), posR(rows, vector<int>(10, cols - 1));

    for(int i = rows - 1; i >= 0; --i) {
        for(int j = cols - 1; j >= 0; --j) {
            int height = v[i][j] - '0';

            // find top distance
            int di{rows - 1};
            for(int i = height; i < 10; ++i) {
                di = min(di, posD[j][i]);
            }

            int dd = di - i;

            // find left distance
            int rj{cols - 1};
            for(int j = height; j < 10; ++j) {
                rj = min(rj, posR[i][j]);
            }

            int rd = rj - j;

            scenicScore[i][j] *= dd * rd;

            posD[j][height] = i;
            posR[i][height] = j;

            res = max(res, scenicScore[i][j]);
        }
    }

    for(auto &row: scenicScore) {
        for(auto &x: row) {
            cout << x << " ";
        }
        cout << endl;
    }

    cout << res << endl;
}
