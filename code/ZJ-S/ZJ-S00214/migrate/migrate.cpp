#include<bits/stdc++.h>
using namespace std;
int c,t;
int n;
long long a[5010];
long long d;
struct node{
	int v;
	long long zhi;
};
long long dp[5010];
long long mn[5010];
void solve(){
	cin>>n>>d;
	memset(dp,0,sizeof dp);
	long long ans=0;
	int fl=0;
	vector<int> mp[5010];
	for(int i=0;i<=n+5;i++) mn[i]=1e18+10;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i!=1 && a[i]-a[i-1]!=a[i-1]-a[i-2]) fl=0;
	}
	if(fl==1){
		long long ans=0;
		long long sum=(d/(a[2]-a[1]))+1;
		long long x=sum;
		for(int i=1;i<=n;i++){
			ans+=n-sum;
			if(n-sum<=0) break;
			sum+=x;
		}
		cout<<ans<<endl;
		return ;
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[j]-a[i]>d) break;
			mp[i].push_back(j);
			mp[j].push_back(i);
		}
	}
	mn[1]=0;
	for(int i=1;i<=n;i++){
		if(i!=1) mn[i]=mn[i-1];
		long long minx=1e18+10;
		for(int j=0;j<mp[i].size();j++){
			int v=mp[i][j];
			if(v>i) continue;
			minx=min(minx,mn[v]+1);
		}
		if(minx>2e17) minx=mn[i-1]+1;
		if(i!=1) mn[i]=minx;
		int cnt=0;
		for(int j=1;j<i;j++){
			if(mn[j]==mn[i]-1) cnt++;
		}
		if(cnt==2) ans++;
	}
	cout<<ans<<endl;
	return ;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--) solve();
	return 0;
}
