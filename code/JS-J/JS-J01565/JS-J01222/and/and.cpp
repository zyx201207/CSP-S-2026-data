#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,ans;
int a[200005];
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    reverse(a+1,a+n+1);
    ans=a[1];
    for(int i=2;i<=m;i++){
        ans=(ans&a[i]);
    }
    cout<<ans;
    return 0;
}