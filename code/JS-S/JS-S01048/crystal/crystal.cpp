#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
const int N=5e5+10;
int a[N];
int maxn=-1;
int b[N];

void solve(){
    int ans=-1;
    for(int i=n;i>=1;i--){
        for(int j=i;j>=1;j--){
            if(a[i]*(i-j+1)-b[i]+b[j-1]<=m)ans=max(ans,i-j+1);
        }
    }
    cout<<ans;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        maxn=max(maxn,a[i]);
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        b[i]=b[i-1]+a[i];
    }
    if(maxn<=100000){
        solve();
        return 0;
    }
    else{
        int k=a[2]-a[1];
        for(int i=n-1;i>=1;i--){
            if(k*i*(i+1)/2<=m){
                cout<<i+1;
                return 0;
            }
        }
    }
    return 0;
}
