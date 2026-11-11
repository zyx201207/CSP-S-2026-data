#include<bits/stdc++.h>
#define LANH using
#define AK namespace
#define CSPS std
LANH AK CSPS;
typedef long long ll;
int c,n,m,d,q;
int w[500009];
vector<pair<int,ll> >sd[500009];
ll dp[509][509];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);
	}
	for(int i=1,x,y,z;i<=n;i++){
		scanf("%d",&x);
		while(x--){
			scanf("%d%d",&y,&z);
			sd[y].push_back({i,z});
		}
		for(int j=1;j<=n;j++){
			dp[i][j]=1e18;
		}
		dp[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		for(pair<int,ll>j:sd[i]){
			for(pair<int,ll>k:sd[i]){
				if(j.first==k.first)continue;
				(dp[j.first][k.first]>j.second+k.second)&&(dp[j.first][k.first]=j.second+k.second);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				(dp[i][j]>dp[i][k]+dp[k][j])&&(dp[i][j]=dp[i][k]+dp[k][j]);
			}
		}
	} 
	int l,r;
	while(q--){
		scanf("%d%d",&l,&r);
		ll minn=8e18;
		for(pair<int,ll>j:sd[l]){
			for(pair<int,ll>k:sd[r]){
				(minn>j.second+k.second+dp[j.first][k.first])&&(minn=j.second+k.second+dp[j.first][k.first]);
			}
		}
		printf("%lld\n",minn+w[l]+w[r]);
	}
	return 0;
}

