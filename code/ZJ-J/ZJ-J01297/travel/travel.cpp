#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    cin>>s1>>s2>>s3>>s4;
    if(s1==s3)cout<<1;
    else cout<<0;
    if(s1==s3&&s2[0]==s4[0]&&s2[1]==s4[1])cout<<1;
    else cout<<0;
    if(s1==s3&&s2[0]==s4[0]&&s2[1]==s4[1]&&(s2[2]<='C'&&s4[2]<='C'||s2[2]>='D'&&s4[2]>='D'))cout<<1;
    else cout<<0;
    if(s1==s3&&s2[0]==s4[0]&&s2[1]==s4[1]&&abs(s2[2]-s4[2])==1&&min(s2[2],s4[2])!='C')cout<<1;
    else cout<<0;
    return 0;
}