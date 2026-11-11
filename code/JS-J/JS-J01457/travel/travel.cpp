#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    char s1[6],s2[6];
    bool check=false,check1=false;
    for(int i=1;i<=5;i++)cin>>s1[i];
    for(int i=1;i<=5;i++)cin>>s2[i];
    if(s1[1]==s2[1]&&s1[2]==s2[2]){
        cout<<1;
        check=true;
    }else{
        cout<<0;
    }
    if(s1[3]==s2[3]&&s1[4]==s2[4]&&check){
        cout<<1;
        check1=true;
    }else{
        cout<<0;
    }
    ll q=(s1[5]-65),w=(s2[5]-65);
    if(!check||!check1){
        cout<<0;
    }else if(q<=2&&w<=2){
        cout<<1;
    }else if(q>=3&&w>=3){
        cout<<1;
    }else{
        cout<<0;
    }
    if(abs((q-w))==1&&check&&check1)cout<<1;
    else cout<<0;
    return 0;
}
