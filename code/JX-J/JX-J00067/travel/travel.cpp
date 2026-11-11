#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,x_1,x_2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    bool c=(c1==c2);
    cout<<c;      //-------1
    x_1=s1[0]+s1[1];
    x_2=s2[0]+s2[1];
    int seat_1=(s1[2]-'A'+1);
    int seat_2=(s2[2]-'A'+1);
    bool f=(x_1==x_2);
    cout<<(c&&f); //-----2
    bool side;
    if((c1==c2)&&((seat_1<=3&&seat_2<=3)||(seat_1>=4&&seat_2>=4))){
        side=1;
    }
    else side=0;
    cout<<(c&&side&&f);//----3
    if(c&&side&&f){     //----4
        if(seat_1-seat_2==1||seat_2-seat_1==1){
            cout<<1;
        }
        else cout<<0;
    }
    else cout<<0;
    return 0;
}
