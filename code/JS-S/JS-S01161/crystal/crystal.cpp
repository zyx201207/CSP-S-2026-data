#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
const int N = 5e5 + 5;
int a[N],sum[N];
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","r",stdin);
    cin>>n>>m;
    if(m==0){
        cout<<1;
        return 0;
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
    int ans=1,r=0;
    for(int l=1;l<=n;l++){
        if(r<l){
            r++;
        }
        while(a[r+1]*(r-l+2)-(sum[r+1]-sum[l-1])<=m&&r<=n){
            r++;
        }
        ans=max(ans,r-l+1);
    }
    ans=min(ans,n);
    cout<<ans;
    return 0;
}
