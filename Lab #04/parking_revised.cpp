# pragma warning (disable:4819)
#include <iostream>
using namespace std;

int park[1000]; // �迭�� �̷��� �����ϴ� ����. c++���� �迭 ����

int main() {
    int K, N;
    cin >> K >> N;
    int cars = 0;
    int slot = K; // SLOT : ������ ���� ��
     // ���� �������ִ� ���� �� => ���߿� SLOT�� 1/3�� �Ǹ� ����ϴ� �ٰŰ� �Ǿ���
    for (int i = 0 ; i < N ; i++ )
    {
        int car_number;
        cin >> car_number;
        bool work = false;	//������������ ���� ���������� ���� ������ work�� 0�� ����

        if (car_number > 0){
            for(int j=0; j<slot ; j++)
            {
                if (cars==slot)
                {
                    park[slot] = car_number;
                    slot *= 2;
                    cars++;
                    break;
                }

                if(park[j]==0)
                {
                    park[j] = car_number;
                    cars++; // ���� ��������  cars�� 1�� ����
                    break;
                }

            }

        }

        else if(car_number<0) // else�ص� �Ȱ�����
        {
            for(int j=0 ; j< slot ; j++){
                if((car_number * -1) == park[j]){
                    park[j] = 0;
                    cars--;
                    work = true;}
                if((work==1) && (slot/3 >=K) && (slot/3)>=cars)
                {
                    int temp_slot[slot];
                    for(int i =0; i < slot ; i++)
                    {
                        for(int k=0; k< slot ;k++)
                        {
                            if(temp_slot[k] == 0 && park[i]>0)
                            {
                                temp_slot[k] = park[i];
                                park[i] = 0;
                                break;
                            }
                        }
                    }
                    slot /= 2;
                    for (int i =0 ; i < slot ; i++)
                    {
                        park[i] = temp_slot[i];
                    }
                }
            }
        }
    }

    for (int i=0 ; i < slot ; i++)
    {
        if(park[i] > 0)
        {
            cout<<i+1<<' '<<park[i]<<endl;
        }
    }
}

