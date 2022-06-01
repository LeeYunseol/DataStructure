#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

struct Node {
	string name;
	Node* parent;	//부모 노드
	vector<Node*>child;	//자식 노드
	int minion_num;	//부하의 수
	int level;	//계층 (boss에 얼마나 가까운지)
	int down_level;	//관할 계층의 수
};

Node* make_new_node(string name) {
	Node* temp = new Node;
	temp->name = name;
	temp->parent = NULL;
	temp->minion_num = 0;
	temp->level = 0;
	return temp;
}

void make_relationship(Node* Person, Node* Boss) {
	Boss->child.push_back(Person);
	Person->parent = Boss;
}

bool cmp_level(Node* a, Node* b) {
	if (a->level > b->level) {	//레벨을 기준으로 내림차순 정렬
		return true;
	}
	return false;
}

//부하직원 내림차순, 레벨 오름차순, 관할계층(down_level) 내림차순, 이름 빠를수록 정렬 후 출력
bool cmp_final(Node* a, Node* b) {
	if (a->minion_num > b->minion_num) {	//부하직원 내림차순
		return true;
	}
	else if (a->minion_num == b->minion_num) {
		if (a->level < b->level) {	//레벨 오름차순
			return true;
		}
		else if (a->level == b->level) {
			if (a->down_level > b->down_level) {	//관할계층 내림차순
				return true;
			}
			else if (a->down_level == b->down_level) {	//이름 빠를수록
				if (a->name < b->name) {
					return true;
				}
			}
		}
	}

	return false;
}

int main(void) {

	int N;	//노드의 수
	cin >> N;

	vector<Node*> members;	//조직에 속한 사람들

	string temp1, temp2;	//PERSON BOSS
	for (int i = 0; i < N - 1; i++) {

		bool have = false;
		cin >> temp1 >> temp2;

		for (int j = 0; j < members.size(); j++) {	//person이 존재하는지
			if (members[j]->name == temp1) {
				have = true;
				break;
			}
		}
		if (!have) {
			Node* temp = make_new_node(temp1);
			members.push_back(temp);
		}

		have = false;
		for (int j = 0; j < members.size(); j++) {	//boss가 존재하는지
			if (members[j]->name == temp2) {
				have = true;
				break;
			}
		}
		if (!have) {
			Node* temp = make_new_node(temp2);
			members.push_back(temp);
		}

		Node* temp3 = NULL;
		for (int j = 0; j < members.size(); j++) {
			if (members[j]->name == temp1) {
				temp3 = members[j];
				break;
			}
		}

		Node* temp4 = NULL;
		for (int j = 0; j < members.size(); j++) {
			if (members[j]->name == temp2) {
				temp4 = members[j];
				break;
			}
		}
		make_relationship(temp3, temp4);
	}

	//1등 보스(root) 구하기
	Node* root = NULL;
	for (int i = 0; i < members.size(); i++) {
		if (members[i]->parent == NULL) {
			root = members[i];
			members[i]->level = 0;
		}
	}

	int max_level = 0;
	//레벨 구하기
	queue<Node*> Q;
	Q.push(root);
	while (!Q.empty()) {
		Node* cur = Q.front();
		Q.pop();
		if (cur->level > max_level) {
			max_level = cur->level;
		}
		for (int i = 0; i < cur->child.size(); i++) {
			Q.push(cur->child[i]);
			cur->child[i]->level = cur->level + 1;
		}
	}

	//레벨을 기준으로 내림차순 정렬
	sort(members.begin(), members.end(), cmp_level);

	//높은 레벨부터
	for (int i = 0; i < members.size(); i++) {
		//부하수 업데이트
		if (members[i]->child.size() == 0) {	//만약 자식이 없으면 자식 수 0
			members[i]->minion_num = 0;
		}
		//만약 자식이 있으면 자식 수 += 자식의 자식수
		else {
			members[i]->minion_num += members[i]->child.size();
			for (int j = 0; j < members[i]->child.size(); j++) {
				members[i]->minion_num += members[i]->child[j]->minion_num;
			}
		}

		//관할 계층 업데이트
		if (members[i]->child.size() == 0) {	//만약 자식이 없으면 down_level = 0;
			members[i]->down_level = 0;
		}
		else {	//만약 자식이 있으면 down_level이 가장 큰 자식의 down_level + 1로 업데이트
			int max_dept = 0;
			for (int j = 0; j < members[i]->child.size(); j++) {
				if (members[i]->child[j]->down_level > max_dept) {
					max_dept = members[i]->child[j]->down_level;
				}
			}
			members[i]->down_level = max_dept + 1;
		}
	}

	//부하직원 내림차순, 레벨 오름차순, 관할계층(down_level) 내림차순, 이름 빠를수록 정렬 후 출력
	sort(members.begin(), members.end(), cmp_final);

	for (int i = 0; i < members.size(); i++) {
		cout << members[i]->name << endl;
	}

	/*
	for (int i = 0; i < members.size(); i++) {
		cout << members[i]->name << ' ' << members[i]->level << ' ' << members[i]->minion_num << ' ' << members[i]->down_level << ' ' << endl;
	}
	*/

	return 0;
}