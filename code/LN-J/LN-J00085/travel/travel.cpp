#include<bits/stdc++.h>
using namespace std;
int a,c;
string b,d;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b>>c>>d;
    if(a==c){
        cout<<'1';
        int b1=b.substr(0,2)-'0',d1=d.substr(0,2)-'0';
        if(b1==d1){
            cout<<'1';
            char b2=b.substr(2,1),d2=d.substr(2,1);
            if(b2==d2){
                cout<<'1';
                if((b2=='A'&&d2=='B')||(b2=='B'&&d2=='A')||(b2=='C'&&d2=='B')||(b2=='B'&&d2=='C')||(b2=='D'&&d2=='F')||(b2=='F'&&d2=='D')){
                    cout<<'1';
                }
                else{
                    cout<<'0';
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
