#include<bits/stdc++.h>
#define int long long
using namespace std;
int a,b,ans;
string s1,s2;
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>s1>>b>>s2;
    if(a==b){
        cout<<1;

    if(s1[1]==s2[1]&&s1[0]==s2[0]){
        cout<<1;

    if(s1[2]<'D'){
        if(s2[2]<'D'){
            cout<<1;
            cout<<(s1[2]==s2[2]-1||s1[2]==s2[2]+1);
        }else{
              cout<<"00";
        }
    }else{
        if(s2[2]>'C'){
            cout<<"11";
        }else{
            cout<<"00";
        }
    }
    }else cout<<"000";
    }else cout<<"0000";
    return 0;
}
