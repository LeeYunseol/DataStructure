#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    long long bmap[64] = {0,};
    long long num = 0;

    // 숫자 다 넣어주기
    for (int i=0 ; i <64 ; i ++)
    {
        scanf("%lld", &num);
        bmap[i] = num;
    }
    // 여기서 bmap[i]를 2진수로 변환하고 전치행렬로 바꿔주기
    long long temp, tmap[64] = {0,};
    for (int i = 0 ; i<64 ; i++)
    {
        temp = bmap[i];
        for (int j=63 ; j >=0 ; j--)
        {
            // & : and, |= : or(+=와 비슷한 개념)
            // 그림을 보면 bm 의 첫째행이 tm의 첫째 열임
            tmap[j] |= ((temp&1)<<(63-i));
            temp = temp >> 1;
        }
    }

    for (int i=0 ; i<64 ; i++)
    {
        cout << tmap[i] << endl;
    }

    return 0;
}
