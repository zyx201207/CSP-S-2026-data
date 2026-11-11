#include<bits/stdc++.h>
using namespace std;
int solve(string s){
    int ans=s[0];

    ans=ans*10+s[1];
    return ans;
}
int ch[10];
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int c1,c2,r1=0,r2=0,a1=0,a2=0;
    string s1,s2;

    cin>>c1>>s1>>c2>>s2;
    r1=solve(s1);
    r2=solve(s2);
    ch[1]=s1[2]-'A';
    ch[2]=s2[2]-'A';
    if(c1!=c2){
        cout<<"0000";
        return 0;
    }else{
        cout<<"1";
    }
    if(r1!=r2){
        cout<<"000";
        return 0;
    }else{
        cout<<"1";
    }
    if(ch[1]<3&&ch[2]<3){
        cout<<"1";
    }else if(ch[1]>=3&&ch[2]>=3){
        cout<<"1";
    }else{
        cout<<"00";
        return 0;
    }
    sort(ch+1,ch+3);
    if(ch[1]==0&&ch[2]==1)cout<<"1";
    else if(ch[1]==1&&ch[2]==2)cout<<"1";
    else if(ch[1]==3&&ch[2]==5)cout<<"1";
    else cout<<"0";
    return 0;
}
