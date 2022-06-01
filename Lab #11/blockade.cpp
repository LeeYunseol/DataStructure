#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

int g[200][200];
int tg[200][200];

int main() {
	int N;
	cin >> N;

	vector<string> city;

	string city_name;
	int num;
	for (int i = 0; i < N; i++) {
		cin >> city_name;
		city.push_back(city_name);
		for (int j = 0; j < N; j++) {
			cin >> num;
			g[i][j] = num;
			g[j][i] = num;
			tg[i][j] = num;
			tg[j][i] = num;
		}
	}
	cin >> num;

	vector<int> city_temp;
	for (int i = 0; i < N; i++) {

		for (int j = 0; j < N; j++) {
			tg[i][j] = 0;
			tg[j][i] = 0;
		}

		int connected_vertex = 0;
		vector<bool> visited(N, false);

		int start = 0;
		if (i == 0) start = 1;

		stack<int> S;
		S.push(start);
		visited[start] = true;
		while (!S.empty()) {
			int cur = S.top();
			S.pop();
			for (int j = 0; j < N; j++) {
				if (visited[j]) continue;
				if (!tg[cur][j]) continue;
				S.push(j);
				visited[j] = true;
			}
		}

		for (int j = 0; j < N; j++) {
			if (visited[j]) {
				connected_vertex++;
			}
		}
		if (connected_vertex != N - 1) {
			city_temp.push_back(i);
		}

		for (int j = 0; j < N; j++) {
			tg[i][j] = g[i][j];
			tg[j][i] = g[j][i];
		}

	}

	if (!city_temp.size()) {
		cout << "None";
	}
	else {
		int max_index = city_temp[0];
		int max = 0;
		for (int i = 0; i < N; i++) {
			max += g[max_index][i];
		}

		for (int i = 1; i < city_temp.size(); i++) {
			int new_index = city_temp[i];
			int new_max = 0;
			for (int j = 0; j < N; j++) {
				new_max += g[new_index][j];
			}

			if (new_max > max) {
				max_index = new_index;
				max = new_max;
			}
		}
		cout << city[max_index];
	}
}
