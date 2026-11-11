#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.in","r",stdin);
    int c1[1],c1[2],c2[1],c2[2],s1[1],s1[2],s2[1],s2[2];
    char s1[3],s2[3];
    cin>>c1>>s1>>c2>>s2;
    if(c1[1]*10+c1[2]==c2[1]*10+c2[2])
    {cout<<1;
    if(s1[1]*10+s1[2]==s2[1]*10+s2[2])
    {cout<<1;
    if(s1[3]>='a'&&s1[3]<='c'&&s2[3]>='a'&&s2[3]<='c'||s1[3]>='d'&&s2[3]>='d')
    {cout<<1;
    if(abs(s1[3]-s2[3])==1)
    cout<<1;
    else
    cout<<0;}
    else
    cout<<"00";
    }
    else
    cout<<"000";
    }
    else
    cout<<"0000";
    return 0;
}
