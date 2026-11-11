#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string s1,s2,s3,s4,s5,s6;
    char a,b;
    cin>>s1>>s2>>s3>>s4;
    if(s1==s3) cout<<"1";
    else cout<<"0";
    for(int i=0;i<=4;i++){
        if(s2[i]>='0'&&s2[i]<='9') s5[i]+=s2[i];
        if(s4[i]>='0'&&s4[i]<='9') s6[i]+=s4[i];
        if(s2[i]>='A'&&s2[i]<='F') a=s2[i];
        if(s4[i]>='A'&&s4[i]<='F') b=s4[i];
    }
    cout<<(s5==s6?"1":"0");
    if((s5==s6&&(((a=='A'||a=='B'||a=='C')&&(b=='A')||(b=='B')||(b=='C'))||((((a=='D')||(a=='F'))&&((b=='D')||(b=='F'))))))) cout<<"1";
    else cout<<"0";
    if(abs(a-b)==1&&a!='C'&&a!='D'&&b!='C'&&b!='D') cout<<"1";
    else cout<<"0";
    return 0;
}
