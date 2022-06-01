#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<vector<int>> v(1500, vector<int>(1500, 0));
    int num;
    scanf("%d", &num);

    for(int k = 0; k < num+2; k++)
    {
        int x1, y1, x2, y2;
//        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        cin >> x1;
        if (x1==-1)
        {
             break;
        }
        cin >> y1;
        cin >> x2;
        cin >> y2;
        int left_down_x, left_down_y, right_up_x, right_up_y;
        left_down_x = x1 - x2 / 2;
        left_down_y = y1 - y2 / 2;
        right_up_x = x1 + x2 / 2;
        right_up_y = y1 + y2 / 2;

        // 왼쪽 아래 점과 오른쪽 위 점 사이의 모든 벡터를 1로 만들어주기
        for(int i = left_down_x; i < right_up_x; i++)
        {
            for(int j = left_down_y; j < right_up_y; j++)
            {
                v[i][j] = 1;
            }
        }


    }

    int result = 0;
    for(int i = 0; i < 1500; i++){
        for(int j = 0; j < 1500; j++){
            if(v[i][j] == 1)
                result++;
        }
    }

    printf("%d", result);

    return 0;
}