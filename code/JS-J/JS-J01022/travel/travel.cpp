#include<bits/stdc++.h>
using namespace std;
#define int long long
//mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
string s1,s2,t1,t2;
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>s1>>s2>>t1>>t2;
    if(s1==t1){
        cout<<'1';
    } else{
        cout<<"0000\n";exit(0);
    }
    if(s2[0]==t2[0] && s2[1]==t2[1]){
        cout<<'1';
    } else{
        cout<<"000\n";exit(0);
    }
    if(s2[2]<='C'){
        if(t2[2]<='C'){
            cout<<'1';
        } else{
            cout<<"00\n";exit(0);
        }
    } else if(s2[2]>='D'){
        if(t2[2]>='D'){
            cout<<'1';
        } else {
            cout<<"00\n";exit(0);
        }
    }
    if(s2[2]!=t2[2] && abs((int)s2[2]-(int)t2[2])==1){
        cout<<'1';
    } else {
        cout<<"0";
    }
    cout<<'\n';
}

