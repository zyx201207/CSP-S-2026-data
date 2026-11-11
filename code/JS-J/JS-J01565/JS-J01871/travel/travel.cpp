#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a==c){
        if(b[0]==d[0]&&b[1]==d[1]){
            if((d[2]>='D'&&b[2]>='D')||(b[2]<='C'&&d[2]<='C')){
                if(b[2]+1==d[2]||b[2]-1==d[2]||(b[2]=='D'&&d[2]=='F')||b[2]=='F'&&d[2]=='D'){
                    cout<<1111;
                }
                else{
                    cout<<1110;
                }
            }
            else{
                cout<<1100;
            }
        }
        else{
            cout<<1000;
        }
    }
    else{
        cout<<"0000";
    }
    return 0;
}