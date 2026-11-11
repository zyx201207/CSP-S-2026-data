#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int f1=0,f2=0;
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(s1==s2){
        cout<<"0000";
        return 0;
    }
    if(c1==c1){
        cout<<1;
    }
    else{
        cout<<"0000";
        return 0;
    }
    if(s1[0]==s2[0]&&s1[1]==s2[1]){
        cout<<1;
        f1=1;
    }
    else{
        cout<<0;
    }
    if(f1==0)
    {
        cout<<0;
    }
    else if(s1[2]=='A' || s1[2]=='B' || s1[2]=='C'){
        if(s2[2]=='A' || s2[2]=='B' || s2[2]=='C'){
            cout<<1;
            f2=1;
        }
        else{
            cout<<0;
        }
    }
    else{
        if(s2[2]=='A' || s2[2]=='B' || s2[2]=='C'){
            cout<<0;
        }
        else{
            cout<<1;
            f2=1;
        }
    }
    if(f2!=1){
        cout<<0;
    }
    else if(f1==1 && (s1[2]+1==s2[2] || s1[2]-1==s2[2])){
        cout<<1;
    }
    else if(f1==0 && s1[2]==s2[2] && s1[0]==s2[0] &&(s1[1]+1==s2[1] || s1[1]-1==s2[1])){
        cout<<1;
    }
    else if(s1[2]==s2[2]&& ((s1[0]=='0'&&s1[0]=='9'&&s2[0]=='1'&&s2[1]=='0') || (s2[0]=='0'&&s2[0]=='9'&&s1[0]=='1'&&s1[1]=='0')))
    {
        cout<<1;
    }
    else cout<<0;
    return 0;
}