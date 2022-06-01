#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
	int num, age;
	char sex;
};

int main() {
	int N;				// 등록한 사람들의 수
	cin >> N;

	vector<Node*> old;
	vector<Node*> child;
	vector<Node*> adult;

	old.push_back(NULL);
	child.push_back(NULL);
	adult.push_back(NULL);

	int num, age;
	char sex;

	int old_check = 1;
	int adult_check = 1;

	for (int i = 0; i < N; i++) {
		cin >> num >> age >> sex;

		Node* t = new Node;
		t->num = num;
		t->age = age;
		t->sex = sex;

		if (age >= 61) {	// old
			if (t->sex == 'M') {
				if (old.size() == 1) { old.push_back(t); old_check++; }
				else {
					old.insert(old.begin() + old_check, t);
					old_check++;
				}
			}
			else {
				old.push_back(t);
			}
		}
		else if (age <= 15) {	// child
			child.push_back(t);
		}
		else {					// adult

			if (t->sex == 'F') {
				if (adult.size() == 1) { adult.push_back(t); adult_check++; }
				else {
					adult.insert(adult.begin() + adult_check, t);
					adult_check++;
				}
			}
			else {
				adult.push_back(t);
			}
		}
	}

	// 정답 출력
	for (int i = 1; i < old.size(); i++) {
		cout << old[i]->num << endl;
	}
	for (int i = 1; i < child.size(); i++) {
		cout << child[i]->num << endl;
	}
	for (int i = 1; i < adult.size(); i++) {
		cout << adult[i]->num << endl;
	}
}