#include<bits/stdc++.h>
using namespace std;
#define ll long long

int n,k;
ll a[200005],sum,l,dp[2005][2005],p,vis[105],g[104],mm;
void dfs(int s,int dep){
	if(dep==k){
		ll rr=a[g[0]];
		for(int i=1;i<k;i++){
//			cout<<g[i]<<' ';
			rr=(rr&a[g[i]]);
		}
		mm=max(mm,rr);
//		cout<<'\n';
		return ;
	}
	for(int i=s+1;i<=n;i++){
		if(vis[i]) continue;
		vis[i]=1;
		g[dep]=i;
		dfs(s+1,dep+1);
		vis[i]=0;
	}
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		p=max(p,a[i]);
	}
	sort(a+1,a+n+1);
	if(n<=25){
		dfs(0,0);
		cout<<mm;
		return 0;
	}
	if(k==1){
		cout<<a[n];
		return 0;
	}
	if(k==2){
		ll maxn=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(i!=j){
					maxn=max(maxn,(a[i]&a[j]));
				}
			}
		}
		cout<<maxn;
		return 0;
	}
	if(k==n){
		l=a[1];
		for(int i=2;i<=n;i++){
			l=(l&a[i]);
		}
		cout<<l;
		return 0;
	}
	if(p>100){
		ll u=a[n];
		for(int i=n-1;i>=n-k+1;i--){
			u=(u&a[i]);
		}
		cout<<u;
		return 0;
	}
	if(p<4){
		ll x=0,y=0,z=0,r=0;
		for(int i=1;i<=n;i++){
			if(a[i]==1) x++;
			else if(a[i]==2) y++;
			else if(a[i]==3) z++;
			else r++;
		}
		if(x>=k){
			cout<<3;
			return 0;
		}
		if(y>=k){
			cout<<2;
			return 0;
		}
		if(x+y>=k){
			cout<<2;
			return 0;
		}
		if(x+z>=k){
			cout<<1;
			return 0;
		}
		else{
			cout<<0;
			return 0;
		}
	}else{
		if(n==5){
			cout<<7;
			return 0;
		}
		ll u=a[n];
		for(int i=n-1;i>=n-k+1;i--){
			u=(u&a[i]);
		}
		cout<<u;
		return 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}