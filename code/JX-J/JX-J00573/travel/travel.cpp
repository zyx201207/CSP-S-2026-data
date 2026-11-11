#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m;
string a,b,c,d;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b>>c>>d;
    if(a==c){
        cout<<1;
        if(b[0]==d[0]&&b[1]==d[1]){
            cout<<1;
            if((b[2]<='C'&&d[2]<='C')||(b[2]>='D'&&d[2]>='D')){
                cout<<1;
                if((b[2]=='B'||d[2]=='B')||(b[2]>='D'&&d[2]>='D')){
                    cout<<1;
                }else{
                    cout<<0;
                }
            }else{
                cout<<0;
                cout<<0;
            }
        }else{
            cout<<0;
            cout<<0;
            cout<<0;
        }
    }else{
        cout<<0;
        cout<<0;
        cout<<0;
        cout<<0;
    }
    return 0;
}
