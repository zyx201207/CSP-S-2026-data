#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool check(char c1,char c2){
    if(c1>='A'&&c1<='C'&&c2>='A'&&c2<='C')return 1;
    if(c1>='D'&&c1<='F'&&c2>='D'&&c2<='F')return 1;
    return 0;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)cout<<1;
    else cout<<0;
    if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1])cout<<1;
    else cout<<0;
    if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]&&check(s1[2],s2[2]))cout<<1;
    else cout<<0;
    if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]&&check(s1[2],s2[2])&&((s1[2]-s2[2]==1)||(s2[2]-s1[2]==1)))
        cout<<1;
    else cout<<0;
    return 0;
}
