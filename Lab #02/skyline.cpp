// 배열을 사용해서 푸었다, 입력받을때마다 건물의 높이와 그 시작, 끝을 저장해두고 주어진 건물들을 하나씩 쌓는다고 가정했어요.
// 이미 쌓은 건물과 더 큰 높이의 건물이 겹쳐지는 곳은 if문으로 높이 비교해서 수정해주는 식으로 하나의 높이 지도(?)를 만들었다? 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 배열 선언
// 제시된 범위만큼 배열을 선언하고 0으로 초기화
int x[1000000] = {0, };
int v[1000000] = {0, };
int h[1000000] = {0, };  // 범위
int SKY_LINE[2000000] = {0, };

// 벡터 만들어주기(마지막에 이걸로 호출, 첫번째 과제와 유사)
vector<int> output;


// 스왑 함수
void swap(int& x, int& y)
{
    int temp = x;
    x = y;
    y = temp;
    return ;
}

int main()
{
    int n;
    scanf("%d", &n);
    int floor_coverage = 0;
    for (int i = 0; i < n; i++)
    {
        int s, e, height;
        scanf("%d %d %d", &s, &height, &e);
        x[i] = s;
        v[i] = height;
        h[i] = e;
        // s의 범위를 저장해야함 ( 바닥의 끝을, 처음은 나중에 정렬하고 첫 번째꺼임 )
        if (floor_coverage<(s+e))
        {
            floor_coverage = (s+e);
        }
    }

    // 건물을 쌓는다는 느낌, s 크기 순으로 오름차순 => 그것에 따라 v와 h의 인덱스 순서도 바뀌어야함
    // 선택 정렬
    // i의 범위를 n-1이 아니라 size of를 써서 오류가 났 
    for(int i=0 ; i <  n - 1 ; i++)
    {
        for (int j=i+1 ; j <  n ; j++) {
            if (x[i] > x[j]) {
                swap(x[i], x[j]);
                swap(v[i], v[j]);
                swap(h[i], h[j]);
            }
                // 시작점(s)이 같은데 높이가 다르면 당연히 높은 것을 채택(높이가 낮은 것은 포함되어버림)
            else if (x[i] == x[j] && v[i] < v[j]) {
                swap(x[i], x[j]);
                swap(v[i], v[j]);
                swap(h[i], h[j]);
            }
        }
    }

    // 다 정렬된 상태(s의 크기 순으로)
    // 이제 skyline_height에 높이를 저장 s부터 e까지 다 같은 높이 height를 가질테니

    for(int i=0 ; i<n ; i++)
    {
        for (int j=x[i] ; j<x[i]+h[i] ; j++)
        {
            if (abs(SKY_LINE[j]) < abs(v[i]))
            {
                SKY_LINE[j] = v[i];
            }
        }
    }

    // 이제 높이도 다 정렬해줌
    // 정리된 것을 이용하여 벡터로 호출

    // 맨처음 s와 height는 그냥 가져오기
    output.push_back(x[0]);
    output.push_back(v[0]);
    // 높이를 비교해서 달라지면 그 폭과 높이의 차를 벡터에 집어넣기
    int var = 1;
    for (int s = x[0] ; s < floor_coverage ; s++)
    {
        if (SKY_LINE[s]==SKY_LINE[s+1])
        {
            var++;
        }

        else
        {
            output.push_back(var);
            output.push_back(SKY_LINE[s+1]-SKY_LINE[s]);
            var = 1;
        }
    }

    // 벡터 호출
    for(int i=0 ; i<output.size() ; i++)
    {
        printf("%d ", output[i]);
    }
    return 1;
}

