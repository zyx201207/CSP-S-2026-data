#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin.tie(0);
    int n;

    cin>>n;
    string s;

    while(n--){
        int a;
        char b;
        cin>>a>>b;
        for(int i=1;i<=a;i++) s+=b;
    }
    int ans=0;
    ll l=0;ll r=s.size()-1;
    while(l<=r){
        if(s[l]!=s[r]) {ans++;}
        l++;r--;
    }
    cout<<ans;
}
