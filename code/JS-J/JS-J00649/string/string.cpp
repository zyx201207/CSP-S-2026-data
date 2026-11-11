#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n,sum=0;
    cin>>n;
    string a;
    for(int i=1;i<=n;i++){
        int x;
        string s;
        cin>>x>>s;
        for(int j=0;j<x;j++)a.push_back(s[0]);
    }
    for(int i=0;i<a.size()/2;i++){
        if(a[i]!=a[a.size()-i-1])sum++;
    }
    cout<<sum;
    return 0;
}
