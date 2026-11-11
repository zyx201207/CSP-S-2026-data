#include<bits/stdc++.h>
using namespace std;
struct cp{
    string cx,zw;
};
cp s1,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>s1.cx>>s1.zw>>s2.cx>>s2.zw;
    string an="";
    if(s1.cx==s2.cx){
        an[0]='1';
    }else{
        an="0000";
        cout<<an;
        return 0;
    }
    if(s1.zw[0]==s2.zw[0] && s1.zw[1]==s2.zw[1]){
        an[1]='1';
    }else{
        an="1000";
        cout<<an;
        return 0;
    }
    if(s1.zw[2]=='A' && s2.zw[2]=='B' || s1.zw[2]=='A' && s2.zw[2]=='C' || s1.zw[2]=='B' && s2.zw[2]=='A' || s1.zw[2]=='B' && s2.zw[2]=='C' ||  s1.zw[2]=='C' && s2.zw[2]=='A' || s1.zw[2]=='C' && s2.zw[2]=='B'){
        an[2]='1';
    }else if(s1.zw[2]=='D' && s2.zw[2]=='F' || s1.zw[2]=='F' && s2.zw[2]=='D'){
        an[2]='1';
    }else{
        an="1100";
        cout<<an;
        return 0;
    }
    if(s1.zw[2]=='A' && s2.zw[2]=='B' || s1.zw[2]=='B' && s2.zw[2]=='C' || s1.zw[2]=='B' && s2.zw[2]=='A' || s1.zw[2]=='C' && s2.zw[2]=='B'){
        an[3]='1';
    }else if(s1.zw[2]=='D' && s2.zw[2]=='F' || s1.zw[2]=='F' && s2.zw[2]=='D'){
        an[3]='1';
    }else{
        cout<<"1110";
        return 0;
    }
    cout<<"1111";
    return 0;
}

