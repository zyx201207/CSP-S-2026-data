#include<bits/stdc++.h>
using namespace std;
string s;
#define int long long
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int x;
        char c;
        cin>>x;
        cin>>c;
        for(int j=1;j<=x;j++){
            s+=c;
        }
    }
    int ans=0;
    int l=0,r=s.size()-1;
    while(l<=r){
        if(s[l]!=s[r]) ans++;
        l++,r--;
    }
    cout<<ans;
    return 0;
}
