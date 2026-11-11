#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long minn=1e18;
long long k;
long long n,d;
void dfs(long long beg,long long ed,long long x,long long step){
	if(x==ed){
		if(minn>step){
			k=1;
			minn=step;
		}
		else if(minn==step){
			k++;
		}
		return;
	}
	for(long long i=x+1;i<=n;i++){
		long long lo=a[i]-a[x];
		if(lo<=d){
			dfs(beg,ed,i,step+1);
		}
	}
}
void solve(){
	
	cin>>n>>d;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	long long ans=0;
	for(long long i=1;i<=n;i++){
		for(long long j=i+1;j<=n;j++){
			dfs(i,j,i,0);
			if(k==2) ans++;
			minn=1e9;
			k=0;
		} 
	}
	cout<<ans<<endl;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long c,t;
	cin>>c>>t;
	while(t--){
		solve();
	}
	
	
	return 0;
}
