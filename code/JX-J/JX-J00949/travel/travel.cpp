#include<bits/stdc++.h>
using namespace std;
string c,s,c2,s2;
int sum=0,cnt=0,flag=0;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c>>s;
    cin>>c2>>s2;
    if(c==c2){
        cout<<1;
        flag=1;
    }else cout<<0;

    for(int i=0;i<3;i++){
        if(s[i]==s2[i]&&i<2)sum++;
        if(s[i]>='A'&&s[i]<='C'&&s2[i]>='A'&&s2[i]<='C'&&i==2)cnt=1;
        else if(s[i]=='D'||s[i]=='F'&&s2[i]=='D'||s2[i]=='F'&&i==2)cnt=1;
    }
    if(sum==2&&flag)cout<<1;
    else cout<<0;

    if(cnt&&sum==2&&flag)cout<<1;
    else cout<<0;

    if((int(s[2])==int(s2[2]-1)||int(s[2]-1)==int(s2[2]))&&cnt==1&&sum==2&&flag)cout<<1;
    else cout<<0;
    return 0;
}
