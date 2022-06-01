#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

struct Node {
	string n;
	Node* p;
	vector<Node*>c;
	int num;
	int l;
	int down;
};

Node* new_node(string name) {
	Node* temp = new Node;
	temp->n = name;
	temp->p = NULL;
	temp->num = 0;
	temp->l = 0;
	return temp;
}

void personToBoss(Node* Person, Node* Boss) {
	Boss->c.push_back(Person);
	Person->p = Boss;
}

bool cmp_level(Node* a, Node* b) {
	if (a->l > b->l) {
		return true;
	}
	return false;
}

bool cmp_final(Node* a, Node* b) {
	if (a->num > b->num) {
		return true;
	}
	else if (a->num == b->num) {
		if (a->l < b->l) {
			return true;
		}
		else if (a->l == b->l) {
			if (a->down > b->down) {
				return true;
			}
			else if (a->down == b->down) {
				if (a->n < b->n) {
					return true;
				}
			}
		}
	}

	return false;
}

int main(void) {

	int N;
	cin >> N;

	vector<Node*> mem;

	string temp1, temp2;
	for (int i = 0; i < N - 1; i++) {

		bool have = false;
		cin >> temp1 >> temp2;

		for (int j = 0; j < mem.size(); j++) {
			if (mem[j]->n == temp1) {
				have = true;
				break;
			}
		}
		if (!have) {
			Node* temp = new_node(temp1);
			mem.push_back(temp);
		}

		have = false;
		for (int j = 0; j < mem.size(); j++) {
			if (mem[j]->n == temp2) {
				have = true;
				break;
			}
		}
		if (!have) {
			Node* temp = new_node(temp2);
			mem.push_back(temp);
		}

		Node* temp3 = NULL;
		for (int j = 0; j < mem.size(); j++) {
			if (mem[j]->n == temp1) {
				temp3 = mem[j];
				break;
			}
		}

		Node* temp4 = NULL;
		for (int j = 0; j < mem.size(); j++) {
			if (mem[j]->n == temp2) {
				temp4 = mem[j];
				break;
			}
		}
		personToBoss(temp3, temp4);
	}

	Node* root = NULL;
	for (int i = 0; i < mem.size(); i++) {
		if (mem[i]->p == NULL) {
			root = mem[i];
			mem[i]->l = 0;
		}
	}

	int max_level = 0;
	queue<Node*> Q;
	Q.push(root);
	while (!Q.empty()) {
		Node* cur = Q.front();
		Q.pop();
		if (cur->l > max_level) {
			max_level = cur->l;
		}
		for (int i = 0; i < cur->c.size(); i++) {
			Q.push(cur->c[i]);
			cur->c[i]->l = cur->l + 1;
		}
	}

	sort(mem.begin(), mem.end(), cmp_level);

	for (int i = 0; i < mem.size(); i++) {
		if (mem[i]->c.size() == 0) {
			mem[i]->num = 0;
		}
		else {
			mem[i]->num += mem[i]->c.size();
			for (int j = 0; j < mem[i]->c.size(); j++) {
				mem[i]->num += mem[i]->c[j]->num;
			}
		}

		if (mem[i]->c.size() == 0) {
			mem[i]->down = 0;
		}
		else {
			int max_dept = 0;
			for (int j = 0; j < mem[i]->c.size(); j++) {
				if (mem[i]->c[j]->down > max_dept) {
					max_dept = mem[i]->c[j]->down;
				}
			}
			mem[i]->down = max_dept + 1;
		}
	}

	sort(mem.begin(), mem.end(), cmp_final);

	for (int i = 0; i < mem.size(); i++) {
		cout << mem[i]->n << endl;
	}

	return 0;
}
