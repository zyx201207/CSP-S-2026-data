#include<bits/stdc++.h>
using namespace std;
int car1,car2;
string s1,s2;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>car1>>s1>>car2>>s2;
    if(car1==car2){
        cout<<1;
        if (s1[0]==s2[0] && s1[1]==s2[1]){
            cout<<1;
            if((s1[2]<='c')==(s2[2]<='c')){
                cout<<1;
                if(abs(int(s1[2]-s2[2]))<=1){
                    cout<<1;
                }
                else{
                    cout<<"0";
                }
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
    return 0;
}
