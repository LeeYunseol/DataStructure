# pragma warning (disable:4819)
#include <iostream>
using namespace std;

int park[1000]; // 배열을 이렇게 선언하는 거임. c++에서 배열 선언

int main() {
    int K, N;
    cin >> K >> N;
    int cars = 0;
    int slot = K; // SLOT : 주차장 공간 수
     // 현재 주차돼있는 차의 수 => 나중에 SLOT의 1/3이 되면 축소하는 근거가 되야함
    for (int i = 0 ; i < N ; i++ )
    {
        int car_number;
        cin >> car_number;
        bool work = false;	//주차공간에서 차가 움직였는지 유무 지금은 work가 0인 상태

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
                    cars++; // 차가 들어왔으니  cars에 1이 증가
                    break;
                }

            }

        }

        else if(car_number<0) // else해도 똑같을듯
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

