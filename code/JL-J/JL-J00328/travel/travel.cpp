#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
string a,b,x,y;
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>x>>b>>y;
    if(a==b){
        cout<<1;
        if(x[0]==y[0]&&x[1]==y[1]){
            cout<<1;
            int i=x[2]-'A'+1,j=y[2]-'A'+1;
            if((i<=3&&j<=3)||(i>3&&j>3)){
                cout<<1;
                if(abs(i-j)<=1)cout<<1;
                else cout<<0;
            }
            else cout<<0<<0;
        }
        else cout<<0<<0<<0;
    }
    else cout<<0<<0<<0<<0;
    return 0;
}
