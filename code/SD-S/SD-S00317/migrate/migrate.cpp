#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int c,t;
int n,d;
int x[2000005];
vector<pair<int,int> > g[2000005];
int ju[200005],vis[200005];
void dfs(int p,int fa,int disss){
	if(p==n){
		return ;
	}
	for(auto o:g[p]){
		int w=1,ttt=o.first;
		if(ttt==fa){
			continue;
		}
		if(disss+1<ju[ttt]){
			ju[ttt]=disss;
			vis[ttt]=1;
		}
		else if(disss+1==ju[ttt]){
			vis[ttt]++;
		}
		int po=disss+1;
		dfs(ttt,p,po);
	}
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				if(abs(x[j]-x[i])<=d&&j!=i){
					g[i].push_back({j,1});
				}
				if(abs(x[j]-x[i])>d){
					break;
				}
			}
		}
		int sum=0;
		for(int i=1;i<=n;i++){
			dfs(i,i,0);
			for(int j=i;j<=n;j++){
				if(ju[j]==2){
					sum++;
				}
			}
		}
		cout<<sum<<endl;
		memset(ju,0x3f,sizeof(ju));
		memset(vis,0,sizeof(vis));
	}
	return 0;
}
