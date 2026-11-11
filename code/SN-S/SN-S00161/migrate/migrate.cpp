#include<bits/stdc++.h>
#define int long long
using namespace std;
int qwe,t,n,m,a[2000010],b[2000010],c[2000010],dp[200010],sumh=1,sumt;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>qwe>>t;
	while(t--){
		memset(a,0,sizeof a);
		memset(b,0,sizeof b);
		memset(c,0,sizeof c);
		memset(dp,0,sizeof dp);
		c[1]=0;sumh=1;sumt=0;
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=n;i>=1;i--){
			while(sumh<=sumt&&c[sumh]-a[i]>m){
				sumh++;
			}
			b[i]=sumt-sumh+1;
			c[++sumt]=a[i];
		}
		
	}
	return 0;
}

