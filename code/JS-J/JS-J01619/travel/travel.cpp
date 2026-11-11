//I AK CSP-J
// 100 + 100 + 100 + 100 = 400

#include<bits/stdc++.h>
using namespace std;

inline void solve(){
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2) cout<<1;
    else cout<<0;
    if(c1==c2&&s1.substr(0,2)==s2.substr(0,2)) cout<<1;
    else cout<<0;
    if(c1==c2&&s1.substr(0,2)==s2.substr(0,2)){
        char ch1=s1[2],ch2=s2[2];
        if('A'<=ch1&&ch1<='C'&&'A'<=ch2&&ch2<='C') cout<<1;
        else if('D'<=ch1&&ch1<='F'&&'D'<=ch2&&ch2<='F') cout<<1;
        else cout<<0;
    }else cout<<0;
    if(c1==c2&&s1.substr(0,2)==s2.substr(0,2)){
        char ch1=s1[2],ch2=s2[2];
        if(ch1=='A'&&ch2=='B') cout<<1;
        else if(ch1=='B'&&ch2=='C') cout<<1;
        else if(ch1=='D'&&ch2=='F') cout<<1;
        else cout<<0;
    }else cout<<0;
    cout<<endl;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    solve();
    return 0;
}

