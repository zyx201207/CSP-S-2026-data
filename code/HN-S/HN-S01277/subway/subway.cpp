#include<bits/stdc++.h>
using namespace std;
struct st{
	long long d,t;
};
long long ans,c,n,m,d,q,w[1000000],k[1000000],a[510][50010],t[510][50010],vis[1000000];
vector<st> s[510];
void dfs(long long g,long long z,long long sum){
	if(g==z){
		sum+=w[g];
		ans=min(sum,ans);
		return;
	}
	for(int i=0;i<s[g].size();i++){
		if(vis[s[g][i].d]!=1){
			vis[s[g][i].d]=1;
			dfs(s[g][i].d,z,sum+s[g][i].t);
			vis[s[g][i].d]=0;
		}
		
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k[i];j++){
			for(int h=1;h<=k[i];h++){
				if(a[i][j]!=a[i][h]){
					st ooo;
					ooo.d=a[i][h];ooo.t=t[i][h];
					s[a[i][j]].push_back(ooo);
				}
			}
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		dfs(x,y,w[x]);
		cout<<ans<<'\n';
		ans=1e9;
	}
	return 0;
}
