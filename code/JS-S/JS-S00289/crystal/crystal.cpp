#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=5e5+5;
ll n,m,a[N],ans,pre[N],need,have,want;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        pre[i]=pre[i-1]+a[i];
    }
    for(ll l=1,r=1;l<=n;l++){
        need=(a[r+1]*(r+1-l+1)),have=(pre[r+1]-pre[l-1]),want=need-have;
        while(r+1<=n&&want<=m){
            r++;
            ans=max(ans,r-l+1);
            need=(a[r+1]*(r+1-l+1));
            have=(pre[r+1]-pre[l-1]);
            want=need-have;
        }
    }
    cout<<ans;
    return 0;
}
