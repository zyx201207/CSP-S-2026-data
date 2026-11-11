#include<bits/stdc++.h>
using namespace std;
int c1,c2,k[114514];
char s1[114514],s2[114514];
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    k[1]=(c1==c2?1:0);
    k[2]=(k[1]&&s1[0]==s2[0]&&s1[1]==s2[1]?1:0);
    k[3]=(k[2]&&(s1[2]<'D'&&s2[2]<'D'||s1[2]>'C'&&s2[2]>'C'));
    k[4]=(k[3]&&(s1[2]+1==s2[2]||s2[2]+1==s1[2]));
    cout<<k[1]<<k[2]<<k[3]<<k[4];
    return 0;
}
//please help me RP++
