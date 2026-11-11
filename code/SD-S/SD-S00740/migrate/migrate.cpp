#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
int n,d,x[2000005],from[2000005];
int dis[2000005],dp[2000005];
void solve1(int &t){
	while(t--){
		cin>>n>>d;
		for(int i=1; i<=n; i++) cin>>x[i];
		if(n==1){
			cout<<0<<"\n";
			continue;
		}
		int l=1;
		for(int i=1; i<=n; i++){
			while(l<=i&&x[i]-x[l]>d) l++;
			from[i]=l;
		}
		int ans=0;
		for(int l=1; l<=n; l++){
			dis[l]=0;dp[l]=1;
			int tmpans=0;
			int k=l;
			for(int r=l+1; r<=n; r++){
				from[r]=max(from[r],l);
				if(from[r]>=r) break;
			}
			for(int r=l+1; r<=n; r++){
				if(from[r]>=r) break;
				dis[r]=dis[from[r]]+1;
				k=max(k,from[r]);
				while(k<r&&dis[k]<=dis[r]-1) k++;
				dp[r]=dp[k-1]-dp[from[r]-1];
				if(dp[r]==2) ans++;
				dp[r]+=dp[r-1];
			}
			dp[l]=0;
		}
		cout<<ans<<"\n";
	}
	return;
}
void solve2(int &t){
	while(t--){
		cin>>n>>d;
		int dx=0;
		for(int i=1; i<=n; i++) cin>>x[i];
		if(n==1){
			cout<<"0\n";
			continue;
		}
		dx=x[2]-x[1];
		d/=dx;
		if(d<=1) cout<<0<<"\n";
		else cout<<max(n-1-2*(d-1),0ll)<<"\n";
	}
	return;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(0);
	ios::sync_with_stdio(false);
	int c,t;
	cin>>c>>t;
	if(c>=11&&c<=12) solve2(t);
	else solve1(t);
	return 0;
}
