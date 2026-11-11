#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int car1,car2;
    string seat1,seat2;
    cin>>car1>>seat1>>car2>>seat2;
    if(car1==car2){
        cout<<1;
        if(seat1[0]==seat2[0] && seat1[1]==seat2[1]){
            cout<<1;
            int s1=seat1[2]-'A';
            int s2=seat2[2]-'A';
            if(s1<3 && s2<3 || s1>2 && s2>2){
                cout<<1;
                if((seat1[2]=='A' && seat2[2]=='C') || (seat1[2]=='C' && seat2[2]=='A')){
                    cout<<0;
                }
                else cout<<1;
            }
            else{
                cout<<"00";
            }
        }
        else{
            cout<<"000";
        }
    }
    else{
        cout<<"0000";
    }
    cout<<"\n";
    return 0;
}
