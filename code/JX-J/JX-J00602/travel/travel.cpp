#include<bits/stdc++.h>
using namespace std;
string s1,c1,s2,c2;
bool f1,f2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>s1>>c1>>s2>>c2;
    if(s1!=s2){cout<<"0000";return 0;}
    cout<<"1";
    if(c1[0]!=c2[0]||c1[1]!=c2[1]){cout<<"000";return 0;}
    cout<<"1";
    if(c1[2]>='A'&&c1[2]<='C') f1=1;
    if(c2[2]>='A'&&c2[2]<='C') f2=1;
    if(f1^f2){cout<<"00";return 0;}
    cout<<"1";
    char a1=c1[2],a2=c2[2];
    if(a1>a2) swap(a1,a2);
    if((a1=='D'&&a2=='F')||(a2-a1==1)) cout<<"1";
    else cout<<"0";
    return 0;
}
