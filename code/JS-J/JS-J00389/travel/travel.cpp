#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int rc,xc;
    string rs,xs;
    cin>>rc>>rs>>xc>>xs;
    if(rc==xc)cout<<1;
    else cout<<0;
    if((rc==xc)&&(rs[0]==xs[0]&&rs[1]==xs[1]))cout<<1;
    else cout<<0;
    if((rc==xc)&&(rs[0]==xs[0]&&rs[1]==xs[1])&&((rs[2]=='D'&&xs[2]=='F')||(rs[2]=='F'&&xs[2]=='D')||(rs[2]=='A'&&xs[2]=='B')||
        (rs[2]=='B'&&xs[2]=='A')||(rs[2]=='A'&&xs[2]=='C')||(rs[2]=='C'&&xs[2]=='A')||
        (rs[2]=='B'&&xs[2]=='C')||(rs[2]=='C'&&xs[2]=='B'))){
        cout<<1;
    }
    else cout<<0;
    if((rs[2]=='D'&&xs[2]=='F')||(rs[2]=='A'&&xs[2]=='B')||(rs[2]=='B'&&xs[2]=='C'))cout<<1;
    else cout<<0;
    return 0;
}
