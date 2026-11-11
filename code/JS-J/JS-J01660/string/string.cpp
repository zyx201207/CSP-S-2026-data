#include<bits/stdc++.h>
#define int long long
using namespace std;

int n;string s;

signed main()
{
    
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    
    cin>>n;
    for(int z=0;z<n;z++){
        int t;char b;
        cin>>t>>b;
        for(int y=0;y<t;y++){
            s.push_back(b);
        }
    }
    int ans=0;
    for(int z=0;z<=(s.size()-1)/2;z++){
        if(s[z]!=s[s.size()-1-z]) ans++;
    }
    cout<<ans;
    return 0;
}