#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cout.tie(0);cin.tie(0);
    cin>>c1>>s1>>c2>>s2;
    bool f1=(c1==c2);
    bool f2=(s1[0]==s2[0]&&s1[1]==s2[1]&&f1);
    bool f3=(((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D'))&&f1&&f2);
    bool f4=(abs(s1[2]-s2[2])==1&&f1&&f2&&f3);
    if(f1)cout<<1;
    else cout<<0;
    if(f2)cout<<1;
    else cout<<0;
    if(f3)cout<<1;
    else cout<<0;
    if(f4)cout<<1;
    else cout<<0;
    return 0;
}

