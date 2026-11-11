#include<bits/stdc++.h>
using namespace std;
#define int long long
//const int N;
int c1,c2;
string s1,s2;
void prep();
void init();
void dr();
void work();
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    int T=1;
//    cin>>T;
    prep();
    while(T--){
        init();
        dr();
        work();
    }
    return 0;
}
void prep(){
}
void init(){
}
void dr(){
    cin>>c1>>s1>>c2>>s2;
}
void work(){
    if(c1==c2) cout<<1;
    else cout<<0;
    if(c1==c2&&s1.substr(0,2)==s2.substr(0,2)) cout<<1;
    else cout<<0;
    if(c1==c2&&s1.substr(0,2)==s2.substr(0,2)&&((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')||(s1[2]=='D'||s1[2]=='F')&&(s2[2]=='D'||s2[2]=='F'))) cout<<1;
    else cout<<0;
    if(c1==c2&&s1.substr(0,2)==s2.substr(0,2)&&((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='C')||(s1[2]=='D'&&s2[2]=='F')||(s2[2]=='A'&&s1[2]=='B')||(s2[2]=='B'&&s1[2]=='C')||(s2[2]=='D'&&s1[2]=='F'))) cout<<1;
    else cout<<0;
}
