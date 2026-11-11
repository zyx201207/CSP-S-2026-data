#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
long long w[500009];
map<long long,map<long long,long long>>pp,p;
vector<long long>ss[500009];
long long dp[509][509];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		long long k;
		scanf("%lld",&k);
		for(int j=1;j<=k;j++){
			long long x,y;
			scanf("%lld%lld",&x,&y);
			pp[i][x]=y;
			ss[x].push_back(i);
		}
	}
	memset(dp,0x3f,sizeof(dp));
	for(int i=1;i<=m;i++){
		if(ss[i].size()>1){
			for(int j=0;j<ss[i].size();j++){
				for(int k=j+1;k<ss[i].size();k++){
					dp[ss[i][j]][ss[i][k]]=pp[ss[i][j]][i]+pp[ss[i][k]][i];
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		long long l,r;
		scanf("%lld%lld",&l,&r);
		long long sum=0;
		sum+=w[l]+w[r];
		long long h=1;
		for(int j=0;j<ss[l].size();j++){
			if(pp[ss[l][j]][r]){
				h=0;
				sum+=pp[ss[l][j]][l]+pp[ss[l][j]][r];
			}
		}
		if(h){
			long long ans=1000000009;
			for(int j=0;j<ss[l].size();j++){
				for(int k=0;k<ss[r].size();k++){
					long long ll=ss[l][j];
					long long rr=ss[r][k];
					ans=min(ans,dp[ll][rr]+pp[ll][l]+pp[rr][r]);
				}
			}
			sum+=ans;
		}
		cout<<sum<<endl;
	}
	return 0;
}
