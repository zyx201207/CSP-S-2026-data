#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,k,T,c,j,i,a[2000010],mi[2000010],gs[2000010],ans;
vector<int> f[2000010];
void dfs(int t,int s){
	int i,x,l;
	l=f[t].size();
	if(s<mi[t]) mi[t]=s,gs[t]=1;
	else gs[t]++;
	for(i=0;i<=l-1;i++){
		x=f[t][i];
		if(s+1>mi[x]) continue;
		dfs(x,s+1);
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>k;
		for(i=1;i<=n;i++) cin>>a[i],f[i].clear();
		if(n>5000){
			for(i=2;i<=n;i++) if(a[i]-a[i-1]!=a[2]-a[1]) break;
			if(i>n){
				int gs=k/(a[2]-a[1]);
				if(gs<=1){
					cout<<0<<"\n";
					continue;
				}
				for(i=1;i<=n;i++)
					if(i+gs*2-1<=n) ans++;
					else break;
				cout<<ans<<"\n";
				ans=0;
				continue;
			}
		}
		for(i=1;i<=n;i++)
			for(j=i+1;j<=n;j++)
				if(a[j]-a[i]<=k) f[i].push_back(j);
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++) mi[j]=1e18,gs[i]=0;
			dfs(i,0);
			for(j=1;j<=n;j++) if(gs[j]==2) ans++;
		}
		cout<<ans<<"\n";
		ans=0;
	}
	return 0;
}