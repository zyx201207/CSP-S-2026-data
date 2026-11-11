#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a1,a2,b1,b2;
    cin>>a1>>b1>>a2>>b2;
    string b11=b1.substr(0,2),b21=b2.substr(0,2);
    char b12=b1[2],b22=b2[2];
    if(a1==a2){
        cout<<'1';
        if(b11==b21){
            cout<<'1';
            if((b12=='A'||b12=='B'||b12=='C')&&(b22=='A'||b22=='B'||b22=='C')){
                cout<<'1';
                if(abs(b12-b22)==1){
                    cout<<'1';
                }
                else{
                    cout<<'0';
                }
            }
            else if((b12=='D'||b12=='F')&&(b22=='D'||b22=='F')){
                cout<<"11";
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
