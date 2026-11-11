#include <bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n;
long long m,a[N],sum[N];
long long S(int l,int r){
    return sum[r]-sum[l-1];
}
bool check(long long x){
    long long mn=2e18;
    for(int i=1,j=x;j<=n;i++,j++){
		long long cnt=(j-i+1);
		mn=min(mn,a[j]*cnt-S(i,j));
    }
    return mn<=m;
}
signed main(){
	freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
    long long L=1,R=n,ans=1;
    while(L<=R){
        long long mid=(L+R)>>1;
        if(check(mid)) ans=mid,L=mid+1;
        else R=mid-1;
    }
    cout<<ans;
    return 0;
}
