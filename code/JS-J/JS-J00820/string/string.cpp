#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[200010];
char c[200010];
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i]>>c[i];
    int l=1,r=n,ans=0;
    while(l<r){
        int mn=min(a[l],a[r]);
        a[l]-=mn;
        a[r]-=mn;
        ans+=(c[l]!=c[r])*mn;
        if(a[l])r--;
        else l++;
    }
    cout<<ans;
    return 0;
}
