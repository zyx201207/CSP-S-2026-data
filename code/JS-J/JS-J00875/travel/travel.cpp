#include <bits/stdc++.h>
using namespace std;
bool ans1,ans2,ans3,ans4;
string carR,carX,seatR,seatX;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>carR>>seatR>>carX>>seatX;
    if(carR==carX){
        ans1=1;
    }
    if(ans1&&seatX[0]+seatX[1]==seatR[0]+seatR[1]){
        ans2=1;
    }if(ans2&&'A'<=seatX[2]&&seatX[2]<='C'&&'A'<=seatR[2]&&seatR[2]<='C'){
        ans3=1;
        if(abs(seatX[2]-seatR[2])==1){
            ans4=1;
        }
    }if('D'<=seatX[2]&&seatX[2]<='F'&&'D'<=seatR[2]&&seatR[2]<='F'){
        ans3=1;
        ans4=1;
    }cout<<ans1<<ans2<<ans3<<ans4;
    return 0;
}
