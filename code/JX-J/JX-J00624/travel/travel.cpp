#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string s1,s2;
    int a,b;
    bool line1,line2;//guodao
    cin>>a>>s1>>b>>s2;
    if(s1[2]=='A' || s1[2]=='B' || s1[2]=='C'){
        line1=0;
    }
    else line1=1;
    if(s2[2]=='A' || s2[2]=='B' || s2[2]=='C'){
        line2=0;
    }
    else line2=1;

    if(a==b){//tongyichexiang
        cout<<1;
    }
    else cout<<0;

    if(s1[0]==s2[0] && s1[1]==s2[1] && a==b){//tongyipai
        cout<<1;
    }
    else cout<<0;

    if(line1==line2 && s1[0]==s2[0] && s1[1]==s2[1] && a==b){//tongyice
        cout<<1;
    }
    else cout<<0;

    if((s1[2]=='A' && s2[2]=='B') || 
    (s1[2]=='B' && s2[2]=='C') || (s1[2]=='D' && s2[2]=='F')){//xianglin
		if(s1[0]==s2[0] && s1[1]==s2[1]) cout<<1;
    }
    else cout<<0;
    return 0;
}
