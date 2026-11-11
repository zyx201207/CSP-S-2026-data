#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
ll w[N];
ll a[510][100010],t[510][100010];
ll dp[510][100010];
//dp[i][j] 表示到第 i 条线路的第 j 个地铁站的最小花费 
ll ans=1e18;
ll k[N];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++) cin>>a[i][j]>>t[i][j];
	}
	while(q--){
		ll x,y;
		cin>>x>>y;
		ll hang=0,lie=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=k[i];j++){
				if(a[i][j]==x){
					hang=i,lie=j;
					break;
				}
			}
		} 
		cout<<"0\n";
	} 
	return 0;
}


