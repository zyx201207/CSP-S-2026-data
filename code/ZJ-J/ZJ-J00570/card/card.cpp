#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int n,m,a[N],last[N],sum[N],dp[N],ans[N],f[N];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=n;i;i--){
		sum[i]=1;
		if(last[a[i]]!=0){
			dp[i]=last[a[i]];
			f[i]=1;
		}else dp[i]=i+1,last[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		if(!f[i]) ans[a[i]]+=sum[i];
		sum[dp[i]]+=sum[i];
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}

