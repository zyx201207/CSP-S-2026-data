#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int a[N],sum[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    int ans=0;
    for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	for(int l=1,r=1;l<=n;l++){
		while(r<n&&a[r+1]*(r+2-l)-(sum[r+1]-sum[l-1])<=m)r++;
		ans=max(ans,(r-l+1));
	}
    cout<<ans;
    return 0;
}
