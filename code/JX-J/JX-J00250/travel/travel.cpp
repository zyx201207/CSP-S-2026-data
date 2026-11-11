#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.cpp","r",stdin);
    freopen("travel.cpp","w",stdout);
    string c1,c2,s1,s2;
    cin>>c1>>s1>>c2>>s2;
    int q11,q22;
    q11=c1[1]-'0'+(c1[0]-'0')*10;
    q22=c2[1]-'0'+(c2[0]-'0')*10;
    if(q11==q22) cout<<1;
    else cout<<0;
    int q1,q2;
    q1=s1[1]-'0'+(s1[0]-'0')*10;
    q2=s2[1]-'0'+(s2[0]-'0')*10;
    if(q1==q2) cout<<1;
    else cout<<0;
    if(s1[2]=='D'||s2[2]=='D'){
        if(s1[2]=='D'){if(s2[2]=='F') cout<<1;else cout<<0;}
        else{if(s1[2]=='F') cout<<1;else cout<<0;}
    }
    else if(abs(s1[2]-s2[2])==1||(abs(s1[2]-s2[2])==2)) cout<<1;
    else cout<<0;
    if((s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D')) cout<<1;
    else if(abs(s1[2]-s2[2])==1&&s1[2]!='D'&&s2[2]!='D') cout<<1;
    else cout<<0;
    return 0;
}
