#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    int a=0;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2) a++;
    if(a==1){
        if(s1[0]==s2[0]&&s1[1]==s2[1]){
            a++;
        }
    }
    if(a==2){
        if(s1[2]=='A'&&s2[2]=='B') a+=2;
        else if(s1[2]=='A'&&s2[2]=='C') a++;
        else if(s1[2]=='B'&&s2[2]=='C') a+=2;
        else if(s1[2]=='D'&&s2[2]=='F') a+=2;
    }
    if(a==0) cout<<"0000";
    else if(a==1) cout<<"1000";
    else if(a==2) cout<<"1100";
    else if(a==3) cout<<"1110";
    else if(a==4) cout<<"1111";
    return 0;
}
