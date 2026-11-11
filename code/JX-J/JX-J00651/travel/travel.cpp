#include<bits/stdc++.h>
#define int long long
using namespace std;
int r,x;
string rr,xx;
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    cin>>r;
    cin>>rr;
    cin>>x;
    cin>>xx;
    if(r==x)cout<<1;
    else {
        cout<<0<<0<<0<<0;
        return 0;
    }
    if(rr[0]==xx[0]&&rr[1]==xx[1])cout<<1;
    else {
        cout<<0<<0<<0;
        return 0;
    }
    char a=rr[2],b=xx[2];
    if((a>='A'&&a<='C'&&b>='A'&&b<='C')||(a>='D'&&b>='D'))cout<<1;
    else {
        cout<<0<<0;
        return 0;
    }
    if((b-a==1)||(a-b==1))cout<<1;
    else cout<<0;
    return 0;
}
