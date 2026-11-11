#include<bits/stdc++.h>
#define ll long long
using namespace std;
int c,T,n,t,h,gs[2005][2005],book[2005];
ll a[1000005],dp[2005][2005],m;
struct node{
	int to,step;
}q[1000005];
int main(){
	ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dp[i][j]=2e18;
				gs[i][j]=0;
			}
		}
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++) book[j]=0;
			h=1,t=0;
			q[++t]={i,0};
			while(h<=t){
				int u=q[h].to,w=q[h].step;
				h++;
				if(dp[i][u]>w){
					dp[i][u]=w;
					gs[i][u]=1;
				} 
				else if(dp[i][u]==w) gs[i][u]++;
				else continue;
				for(int k=u+1;k<=n;k++){
					if(abs(a[u]-a[k])<=m){
						q[++t]={k,w+1};
					}
				}
			}
		}
		int sum=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(gs[i][j]==2) sum++;
			}
		}
		cout<<sum<<"\n";
	}
	return 0;
}