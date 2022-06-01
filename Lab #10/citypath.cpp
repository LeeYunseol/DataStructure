#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int graph[100][100];

int main() {
	int N;
	cin >> N;

	int num;
	for (int i = 0; i < N; i++) {
		while (true) {
			cin >> num;
			if (!num) break;
			if (num == i + 1) continue;
			graph[num - 1][i] = 1;
			graph[i][num - 1] = 1;
		}
	}

	int max = 0;

	for (int i = 0; i < N; i++) {
		vector<int> visited(N + 1, false);
		vector<int> dist(N + 1, INT_MAX);

		dist[i] = 0;
		visited[i] = true;
		for (int j = 0; j < N; j++) {
			if (graph[i][j]) {
				dist[j] = 1;
			}
		}

		for (int j = 0; j < N - 2; j++) {
			int cur = N;
			for (int k = 0; k < N; k++) {
				if (visited[k]) continue;
				if (dist[k] < dist[cur]) cur = k;
			}
			visited[cur] = true;

			for (int k = 0; k < N; k++) {
				if (visited[k]) continue;
				if (!graph[cur][k]) continue;

				int newDist = dist[cur];
				for (int l = 0; l < N; l++) {
					if (graph[cur][l]) {
						newDist++;
					}
				}
				if (newDist < dist[k]) {
					dist[k] = newDist;
				}
			}

		}

		int new_max = 0;
		for (int j = 1; j < N; j++) {
			if (dist[j] == INT_MAX) continue;
			if (dist[j] > new_max)
				new_max = dist[j];
		}

		if (max < new_max) {
			max = new_max;
		}
	}

	cout << max;
}