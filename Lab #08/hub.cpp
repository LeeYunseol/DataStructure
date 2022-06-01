#include <iostream>
#include <stack>
using namespace std;

int main(void) {
	
	int N;
	cin >> N;

	int** graph;
	graph = new int* [N + 1];
	for (int i = 0; i <= N; i++) {
		graph[i] = new int[N + 1];
	}
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= N; j++) {
			graph[i][j] = 0;
		}
	}

	for (int i = 0; i < N; i++) {
		int p1, p2;
		cin >> p1 >> p2;
		if (graph[p1][p2] == 0) {
			graph[p1][0]++;
			graph[p2][0]++;
		}
		graph[p1][p2] = 1;
		graph[p2][p1] = 1;
	}

	int biggest = 1;
	for (int i = 1; i <= N; i++) {
		if (graph[i][0] > graph[biggest][0]) {
			biggest = i;
		}
	}

	int count1 = 0;
	for (int i = 1; i <= N; i++) {
		if (graph[i][0] == graph[biggest][0])
			count1++;
	}

	int* visit = new int[N + 1];
	for (int i = 0; i <= N; i++) {
		visit[i] = 0;
	}

	int count = 1;
	stack<int> S;
	visit[biggest] = 1;
	S.push(biggest);
	while (!S.empty()) {
		int cur = S.top();
		S.pop();
		for (int i = 1; i <= N; i++) {
			if (graph[cur][i] && !visit[i]) {
				visit[i] = 1;
				count++;
				S.push(i);
			}
		}
	}

	if (count1 >= 2) {
		cout << 0 << " " << 0 << endl;
	}
	else {
		cout << biggest << ' ' << count << endl;
	}

	int people = count;
	int group = 1;
	for (int i = 1; i <= N; i++) {
		if (!visit[i]) {
			int groupPeople = 0;
			group++;
			stack<int> nS;
			nS.push(i);
			while (!nS.empty()) {
				int cur = nS.top();
				nS.pop();
				for (int i = 1; i <= N; i++) {
					if (graph[cur][i] && !visit[i]) {
						visit[i] = 1;
						groupPeople++;
						nS.push(i);
					}
				}
			}
			if (groupPeople > people) {
				people = groupPeople;
			}
		}
	}

	cout << people << endl;
	cout << group << endl;

	delete[] visit;
	for (int i = 0; i <= N; i++) {
		delete[] graph[i];
	}
	delete[] graph;

	return 0;
}
