#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int n,a[N],m,ans;
int num[N],dp[N];
int sum[N];
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;++i){
		num[i]=a[i];
		sum[i]=sum[i-1]+a[i];
	}
	int nn=unique(num+1,num+1+n)-num-1;
	dp[0]=1;
	for(int i=1;i<=nn;++i){
		int id=upper_bound(a+1,a+1+n,num[i])-a-1,len=id-dp[i-1]+1;
		//cout<<id<<' '<<len<<' ';
		while(len>0&&len*num[i]-(sum[id]-sum[id-len])>m){
			--len;
		}
		//cout<<len<<'\n';
		dp[i]=id-len+1;
		ans=max(ans,len);
	}
	cout<<ans;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	solve();
	return 0;
}
