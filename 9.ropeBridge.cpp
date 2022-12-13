#include<iostream>
#include<set>
#include<utility>
#include<string>
#include<sstream>

using namespace std;

pair<int, int> updateTail(const pair<int, int> &head, pair<int, int> &tail) {
    int hr = head.first, hc = head.second;
    int &tr = tail.first, &tc = tail.second;

    if(abs(hr - tr) > 1 || abs(hc - tc) > 1) {
        if(tc == hc) {
            // move vertically
            tr += hr > tr ? 1 : -1;
        } else if(hr == tr) {
            // move horizontally
            tc += hc > tc ? 1 : -1;
        } else {
            if(hr < tr and hc < tc) {
                // move top-left
                --tr, --tc;
            } else if(hr < tr and hc > tc) {
                // move top-right
                --tr, ++tc;
            } else if(hr < tr and hc < tc) {
                ++tr, ++tc;
            } else {
                ++tr, --tc;
            }
        }
    }

    return tail;
}

int main() {
    string command;
    set<pair<int, int>> tailPositions;

    pair<int, int> head, tail;

    while(getline(cin, command)) {
        istringstream iss{command};
        string dir;
        int steps{};

        iss >> dir >> steps;

        if(dir == "U") {
            while(steps--) {
                --head.first;
                tail = updateTail(head, tail);
                tailPositions.insert(tail);
            }
        } else if(dir == "R") {
            while(steps--) {
                ++head.second;
                tail = updateTail(head, tail);
                tailPositions.insert(tail);
            }
        } else if(dir == "D") {
            while(steps--) {
                ++head.first;
                tail = updateTail(head, tail);
                tailPositions.insert(tail);
            }
        } else {
            while(steps--) {
                --head.second;
                tail = updateTail(head, tail);
                tailPositions.insert(tail);
            }
        }

    }

    cout << tailPositions.size() << endl;
}
