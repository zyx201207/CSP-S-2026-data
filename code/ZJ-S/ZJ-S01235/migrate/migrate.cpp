#include<bits/stdc++.h>
using namespace std;
const int N=2000005;
int c,t,n,d;
int x[N],ans,dp[5005][5005];
bool check(int xx,int yy){
	memset(dp,0,sizeof(dp));
	int minn=1;
	int l=xx;
	for(int i=xx+1;i<=yy;i++){
		if(x[i]-x[l]>d){
			minn++;
			l=i-1;
		}
	}
	if(minn==1) return false;
	dp[xx][0]=1;
	for(int i=xx+1;i<=yy;i++){
		for(int j=i-1;j>=xx;j--){
			if(x[i]-x[j]<=d){
				for(int k=minn;k>=1;k--){
					dp[i][k]+=dp[j][k-1];
				}
			}
		}
	}
	if(dp[yy][minn]==2) return true;
	return false;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>t;
	while(t--){
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(x[j]-x[j-1]>d) break;
				if(check(i,j)) ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}