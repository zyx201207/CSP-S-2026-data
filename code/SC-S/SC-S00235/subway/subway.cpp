#include<bits/stdc++.h>
#define int long long
using namespace std;
struct st{
	int id,num;
};
int c,n,m,d,q,x[500005],vis[505],ans;
vector<st>v[505],s[500005];
void dfs(int o,int tar,int t,int tim){
//	cout<<o<<" "<<tar<<" "<<t<<" "<<tim<<"\n";
	for(int i=0;i<v[t].size();i++){
		if(v[t][i].id==tar){
			ans=min(ans,tim+v[t][i].num+x[tar]);
			return;
		}
	}
	for(int i=0;i<v[t].size();i++){
		if(v[t][i].id!=o){
			for(int j=0;j<s[v[t][i].id].size();j++){
				if(vis[s[v[t][i].id][j].id]==0&&tim+v[t][i].num+s[v[t][i].id][j].num+x[tar]<ans){
					vis[s[v[t][i].id][j].id]=1;
					dfs(v[t][i].id,tar,s[v[t][i].id][j].id,tim+v[t][i].num+s[v[t][i].id][j].num);
					vis[s[v[t][i].id][j].id]=0;
				}
			}
		}
	}
	return;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>x[i];
	}
	for(int i=1;i<=n;i++){
		int t;
		cin>>t;
		for(int j=1;j<=t;j++){
			int a,b;
			cin>>a>>b;
			v[i].push_back({a,b});
			s[a].push_back({i,b});
		}
	}
	for(int i=1;i<=q;i++){
		int l,r;
		cin>>l>>r;
		ans=1000000000000000;
		for(int j=0;j<s[l].size();j++){
			vis[s[l][j].id]=1;
			dfs(l,r,s[l][j].id,s[l][j].num+x[l]);
			vis[s[l][j].id]=0;
		}
		cout<<ans<<"\n";
	}
	return 0;
}