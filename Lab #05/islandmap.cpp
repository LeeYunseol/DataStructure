#include <iostream>
#include <stack>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

#define X first
#define Y second

int main() {
	int dir[4][2] = { {0, -1}, {0, 1}, {1, 0}, {-1, 0} };
	int x, y;
	cin >> x >> y;
	int** map = new int* [x];
	for (int i = 0; i < x; i++) {
		map[i] = new int[y];
		memset(map[i], 0, sizeof(int) * y);
	}
	int** isVisited = new int* [x];
	for (int i = 0; i < x; i++) {
		isVisited[i] = new int[y];
		memset(isVisited[i], 0, sizeof(int) * y);
	}

	int i, j;
	i = j = 0;
	while (true) {
		string str;
		cin >> str;
		if (str == "-1") break;
		for (int k = 0; k < str.length(); k++) {
			map[i][j++] = str.at(k) - '0';
			if (j == y) {
				i++;
				j = 0;
			}
		}
	}

	stack<pair<int, int>> S;
	isVisited[0][0] = true;
	int count_ocean = 1;
	S.push(make_pair(0, 0));

	while (!S.empty()) {
		pair<int, int> cur = S.top();
		S.pop();
		for (int i = 0; i < 4; i++) {
			pair<int, int> next = make_pair(cur.X + dir[i][0], cur.Y + dir[i][1]);
			if (next.X >= x || next.X < 0 || next.Y >= y || next.Y < 0) continue;
			if (isVisited[next.X][next.Y] || map[next.X][next.Y]) continue;
			isVisited[next.X][next.Y] = true;
			count_ocean += 1;
			S.push(next);
		}
	}

	int count_island = x * y - count_ocean;
	cout << count_island;

	for (int i = 0; i < y; i++) {
		delete[] map[i];
		delete[] isVisited[i];
	}
	delete[] map;
	delete[] isVisited;
}