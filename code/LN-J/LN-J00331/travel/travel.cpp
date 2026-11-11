#include<bits/stdc++.h>
using namespace std;
string car1,car2,seat1,seat2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>car1>>seat1>>car2>>seat2;
    if(car1!=car2) printf("0000");
    else{
        printf("1");
        if(seat1[0]!=seat2[0]||seat2[1]!=seat1[1]) printf("000");
        else{
            printf("1");
            int r=seat1[2]-'A';
            int x=seat2[2]-'A';
            if((r>=3&&x<=2)||(r<=2&&x>=3)) printf("00");
            else{
                printf("1");
                if(abs(r-x)==1) printf("1");
                else printf("0");
            }
        }
    }
}
