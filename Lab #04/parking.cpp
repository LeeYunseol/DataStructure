#include <iostream>
using namespace std;

int park[1000];

void init() {
	ios::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
}

int main() {

	init();

	int K, N;
	cin >> K >> N;
	int slot = K;	//현재 주차공간
	int cars = 0;	//현재 주차돼있는 차의 수

	for (int i = 0; i < N; i++) {
		int input;
		cin >> input;
		bool work = false;	//주차공간에서 차가 움직였는지 유무

		if (input > 0) {	//입력한 값이 양수, 차가 들어옴
			for (int j = 1; j <= slot; j++) {
				if (!work && !park[j]) {
					park[j] = input;
					cars++;
					work = 1;
					break;
				}
			}
			if (!work) {
					park[slot + 1] = input;
					slot *= 2;
					cars++;
			}
		}
		else if (input < 0) {	//입력한 값이 음수이면 
			for (int j = 1; j <= slot; j++) {
				if (park[j] * -1 != input)
					continue;
				park[j] = 0;
				cars--;
				work = 1;
			}
			if (slot / 3 >= K && slot / 3 >= cars && work) {
				for (int j = 1; j <= slot; j++) {
					for (int k = 1; k <= slot; k++) {
						if (!park[k]) {
							park[k] = park[j];
							park[j] = 0;
							break;
						}
					}
				}
			}
		}
	}

	for (int i = 1; i <= slot; i++)
		if (park[i])
			cout << i << ' ' << park[i] << endl;
}
