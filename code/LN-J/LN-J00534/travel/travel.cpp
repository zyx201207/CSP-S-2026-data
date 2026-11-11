#include<bits/stdc++.h>
using namespace std;
int p[10];
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    p[s1[2]-'A']=1,p[s2[2]-'A']=1;
    if(c1==c2)cout<<"1";
    else {cout<<"0000";return 0;}
    if(s1[0]==s2[0]&&s1[1]==s2[1])cout<<"1";
    else {cout<<"000";return 0;}
    
    if((p[4]+p[5]==2)||(p[0]+p[1]+p[2]==2))cout<<"1";
    else {cout<<"00";return 0;}
    for(int i=0;i<5;i++){
        if(p[i]+p[i+1]==2){cout<<"1";return 0;}
    }
    cout<<"0";
    return 0;
}