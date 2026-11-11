#include<bits/stdc++.h>
using namespace std;
#define endl "\n"

string s1,s2,c1,c2,p1,p2;//pai lie
char l1,l2;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    p1=s1.substr(0,2),p2=s2.substr(0,2);
    l1=s1[2],l2=s2[2];
    bool b1=(c1==c2),b2=(p1==p2),
    b3=( (l1<='C'&&l2<='C')||(l1>='D'&&l2>='D') ),
    b4=(abs(l1-l2)==1);
    cout<<b1<<(b1&&b2)<<(b1&&b2&&b3)<<(b1&&b2&&b3&&b4)<<'\n';
    return 0;
}