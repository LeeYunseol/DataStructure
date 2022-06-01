// �迭�� ����ؼ� Ǫ����, �Է¹��������� �ǹ��� ���̿� �� ����, ���� �����صΰ� �־��� �ǹ����� �ϳ��� �״´ٰ� �����߾��.
// �̹� ���� �ǹ��� �� ū ������ �ǹ��� �������� ���� if������ ���� ���ؼ� �������ִ� ������ �ϳ��� ���� ����(?)�� �������? 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// �迭 ����
// ���õ� ������ŭ �迭�� �����ϰ� 0���� �ʱ�ȭ
int x[1000000] = {0, };
int v[1000000] = {0, };
int h[1000000] = {0, };  // ����
int SKY_LINE[2000000] = {0, };

// ���� ������ֱ�(�������� �̰ɷ� ȣ��, ù��° ������ ����)
vector<int> output;


// ���� �Լ�
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
        // s�� ������ �����ؾ��� ( �ٴ��� ����, ó���� ���߿� �����ϰ� ù ��°���� )
        if (floor_coverage<(s+e))
        {
            floor_coverage = (s+e);
        }
    }

    // �ǹ��� �״´ٴ� ����, s ũ�� ������ �������� => �װͿ� ���� v�� h�� �ε��� ������ �ٲ�����
    // ���� ����
    // i�� ������ n-1�� �ƴ϶� size of�� �Ἥ ������ �� 
    for(int i=0 ; i <  n - 1 ; i++)
    {
        for (int j=i+1 ; j <  n ; j++) {
            if (x[i] > x[j]) {
                swap(x[i], x[j]);
                swap(v[i], v[j]);
                swap(h[i], h[j]);
            }
                // ������(s)�� ������ ���̰� �ٸ��� �翬�� ���� ���� ä��(���̰� ���� ���� ���ԵǾ����)
            else if (x[i] == x[j] && v[i] < v[j]) {
                swap(x[i], x[j]);
                swap(v[i], v[j]);
                swap(h[i], h[j]);
            }
        }
    }

    // �� ���ĵ� ����(s�� ũ�� ������)
    // ���� skyline_height�� ���̸� ���� s���� e���� �� ���� ���� height�� �����״�

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

    // ���� ���̵� �� ��������
    // ������ ���� �̿��Ͽ� ���ͷ� ȣ��

    // ��ó�� s�� height�� �׳� ��������
    output.push_back(x[0]);
    output.push_back(v[0]);
    // ���̸� ���ؼ� �޶����� �� ���� ������ ���� ���Ϳ� ����ֱ�
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

    // ���� ȣ��
    for(int i=0 ; i<output.size() ; i++)
    {
        printf("%d ", output[i]);
    }
    return 1;
}

