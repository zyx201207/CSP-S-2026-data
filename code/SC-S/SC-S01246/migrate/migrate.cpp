#include<bits/stdc++.h>
using namespace std;
int n,nxt[2000006],lst[2000006],dis[5005][5005],dp[5005][5005];
long long x[2000006],d;
void solvea(){
	long long ans=0;
	cin>>n>>d;
	for(int i=1;i<=n;++i){
		cin>>x[i];
	}
	for(int l=1,r=1;max(l,r)<=n;++l){
		for(;x[r]-x[l]<=d&&r<=n;++r){}nxt[l]=--r;
	}
	for(int l=n,r=n;min(l,r);--r){
		for(;x[r]-x[l]<=d&&l;--l){}lst[r]=++l;
	}
	for(int i=1;i<=n;++i){
		dis[i][i]=0;
		for(int j=i+1;j<=n;++j){
			if(lst[j]<=i){dis[i][j]=1;}else{dis[i][j]=dis[i][lst[j]]+1;}
		}
	}
	for(int len=1;len<=n;++len){
		for(int l=1,r=l+len-1;r<=n;++l,++r){
			if(dis[l][r]<=1){dp[l][r]=1;continue;}
			dp[l][r]=0;
			for(int k=nxt[l];k>l&&1+dis[k][r]==dis[l][r];--k){
				dp[l][r]+=(dp[l][k]*dp[k][r]);
				if(dp[l][r]>2){dp[l][r]=3;break;}
			}
			ans+=(dp[l][r]==2);
		}
	}
	cout<<ans<<endl;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;cin>>c>>t;
	for(++t;--t;){
		solvea();
	}
	return 0;
}