#include<bits/stdc++.h>
using namespace std;
#define llu unsigned long long
#define ll long long

const int maxn=5e3+86;
llu m,n,b[maxn],dp[maxn][maxn];
ll a[maxn];
bool vis[maxn][maxn];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i)scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	b[1]=0;
	for(int i=2;i<=n;++i)b[i]=a[i]-a[i-1];
	int i;
	for(i=2;i<=n;++i){
		bool o=1;
		for(int j=1;j<=n-i+1;++j){
			if(vis[i-1][j])continue;
			dp[i][j]=dp[i-1][j]+(llu)(i-1)*b[i+j-1];
			if(dp[i][j]>m)vis[i][j]=1;
			else o=0;
		}
		if(o)break;
	}
	cout<<i-1<<endl;
	
	
	return 0;
}
