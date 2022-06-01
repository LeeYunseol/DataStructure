#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {

	int w, k, n;
	cin >> w;
	cin >> k;
	cin >> n;

	queue<int> people;
	int temp;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		people.push(temp);
	}

	queue<int> rope;
	rope.push(people.front());
	int totalWeight = people.front();
	int totalPeople = 1;
	people.pop();
	int total = 1;

	while (!people.empty()) {

		if (totalPeople == k) {
			totalWeight -= rope.front();
			totalPeople--;
			rope.pop();
		}

		if (totalWeight + people.front() <= w) {
			rope.push(people.front());
			totalWeight += people.front();
			totalPeople++;
			people.pop();
		}
		else {
			while (!rope.empty()) rope.pop();
			rope.push(people.front());
			totalPeople = 1;
			totalWeight = people.front();
			people.pop();

			total++;
		}
	}

	cout << total;
}