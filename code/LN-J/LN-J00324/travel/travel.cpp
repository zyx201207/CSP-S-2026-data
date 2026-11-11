#include<bits/stdc++.h>
using namespace std;
string s1,c1,s2,c2;
int x,ans,ans1,ans2,ans3;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>s1>>c1>>s2>>c2;
    int cnt = c1[2]-'A';
    int cnt1 = c2[2]-'A';
    if(cnt>cnt1){
        x=cnt-cnt1;
    }
    else{
        x=cnt1-cnt;
    }
    if(s1==s2){
        cout<<1;
    }
    else{
        cout<<"0000";
        return 0;
    }
    if(s1 == s2&&c1[0] == c2[0]&&c1[1] == c2[1]){
        cout<<1;
    }
    else{
        cout<<"000";
        return 0;
    }

    if(c1[2]=='A'||c1[2]=='B'||c1[2]=='C'){
        ans=1;
    }
    if(c2[2]=='A'||c2[2]=='B'||c2[2]=='C'){
        ans1=1;
    }
    if(c1[2]=='D'||c1[2]=='F'){
        ans2=1;
    }
    if(c2[2]=='D'||c2[2]=='F'){
        ans3=1;
    }

    if(s1 == s2&&c1[0] == c2[0]&&c1[1] == c2[1]&&ans==1&&ans1==1){
        cout<<1;
    }
    else if(s1 == s2&&c1[0] == c2[0]&&c1[1] == c2[1]&&ans2==1&&ans3==1){
        cout<<1;
    }
    else{
        cout<<"00";
        return 0;
    }
    if(s1 == s2&&c1[0] == c2[0]&&c1[1] == c2[1]&&ans==1&&ans1==1&&x==1){
        cout<<1;
    }
    else if(s1 == s2&&c1[0] == c2[0]&&c1[1] == c2[1]&&ans2==1&&ans3==1){
        cout<<1;
    }
    else{
        cout<<0;
    }
    return 0;
}

