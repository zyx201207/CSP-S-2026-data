#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],jh[500005],f[500005],ans;
void dfs(int cnt,int x,int s) {
	ans=max(ans,cnt);
	for(int i=x+1; i<=n; i++) {
		if(jh[i]==0&&(s+a[i]+m)%(x+1)==0&&(s+a[i]+m)/(x+1)>=a[i]) {
			jh[i]=1;
			dfs(cnt+1,i,s+a[i]);
			jh[i]=0;
		}
	}
}
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	if(m==0) {
		int s=1;
		for(int i=2; i<=n; i++) {
			if(a[i]!=a[i-1])ans=max(ans,s),s=1;
			else s++;
		}
		ans=max(ans,s);
		cout<<ans<<"\n";
		return 0;
	}
	int jh=0;
	for(int i=2; i<=n; i++)
		if(a[i]!=a[i-1]) {
			jh=1;
			break;
		}
	if(jh==0) {
		if(m<n)cout<<m<<"\n";
		else if(m%n==0)cout<<n<<"\n";
		else cout<<n-1<<"\n";
		return 0;
	}
	jh=0;
	for(int i=3; i<=n; i++)
		if(a[i-1]-a[i-2]!=a[i]-a[i-1]) {
			jh=1;
			break;
		}
	if(jh==0) {
		for(int i=1; i<=n; i++)
			f[i]=f[i-1]+a[i];
		for(int i=1; i<=n; i++)
			if((m+f[i])%i==0&&(m+f[i])/i>=a[i])
				ans=i;
		cout<<ans<<"\n";
		return 0;
	}
	dfs(0,0,0);
	cout<<ans<<"\n";
	return 0;
}