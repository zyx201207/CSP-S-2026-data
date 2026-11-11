#include<bits/stdc++.h>
using namespace std;
namespace migrate{
	const int MAXN=2e6+10;
	int c,t,n;
	long long d;
	long long x[MAXN];
	long long ans;
	long long pre[MAXN],aft[MAXN];
	int cnt;
	int mn;
	void dfs(int l,int r,int sm,int s){
		if(l==r){
			if(s<mn){
				mn=s;
				cnt=1;
			}
			else if(s==mn)
				cnt++;
			return;
		}
		if(sm!=0&&sm+x[l]<=d)
			dfs(l+1,r,sm+x[l],s);
		dfs(l+1,r,sm+x[l],s+1);
		return;
	}
	void solve(){
		cin>>n>>d;
		ans=0;
		for(int i=1;i<=n;i++)
			cin>>x[i];
		long long k=x[2]-x[1];
		if(k>d){
			cout<<"0\n";
			return;
		}
		long long j=d/k;
		if(k==d||j*2-1>n)
			ans=0;
		else
			ans=n-2*j+1;
		if(n<=10){
			ans=0;
			for(int i=1;i<n;i++)
				for(int j=i+1;j<=n;j++){
					cnt=0;
					mn=INT_MAX;
					dfs(i,j,0,0);
					if(cnt==2)
						ans++;
				}
		}
		cout<<ans<<"\n";
		return;
	}
	void work(){
		cin>>c>>t;
		while(t--)
			solve();
		return;
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	migrate::work();
	return 0;
}
/*
0 1
6 1200000000000000000
-1000000000000000000 -600000000000000000 -200000000000000000 200000000000000000 600000000000000000 1000000000000000000
*/
