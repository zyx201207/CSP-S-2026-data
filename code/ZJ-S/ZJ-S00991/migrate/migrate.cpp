#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pi pair<int,int>
#define fi first
#define se second
const int N=1e6+7;
const int M=1e6+7;
int C,n,m,d,q;
int a[N],f[N],g[N],vis[N];
void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++)cin>>a[i];
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int i=1;i<=n;i++)f[i]=1e18,g[i]=vis[i]=0;
		f[i]=0;
		queue<int>q;q.push(i);
		g[i]=1;
		while(q.size()){
			int t=q.front();q.pop();
			if(g[t]>2||vis[t])continue;
			vis[t]=1;
			for(int j=t+1;j<=n;j++){
				if(a[j]-a[t]>d)break;
				if(f[t]+1<f[j])g[j]=g[t],q.push(j),f[j]=f[t]+1;
				else if(f[t]+1==f[j]){
					g[j]+=g[t];
				}
			}
		}
		for(int j=i+1;j<=n;j++){
			ans+=(g[j]==2);
//			if(g[j]==1)cout<<i<<" "<<j<<'\n';
		}
	}
	cout<<ans<<'\n';
}
void solve1(){
	cin>>n>>d;
	for(int i=1;i<=n;i++)cin>>a[i];
	int x=a[2]-a[1];
	if(d/x<=1)cout<<0<<'\n';
	else cout<<max(0ll,n-2*(d/x)+1)<<"\n";
}
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;
	cin>>c>>T;
	while(T--){
		if(c>=11&&c<=12)solve1();
		else solve();
//		else solve2();
	}
	
}