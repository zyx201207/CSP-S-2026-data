#include<bits/stdc++.h>
using namespace std;
#define ll long long
int a[1000005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ll n,m,ans=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        int q=(a[i]&a[i+1]);
        if(q>ans) ans=q;
        q=0;
    }
    cout<<ans;
    return 0;
}
