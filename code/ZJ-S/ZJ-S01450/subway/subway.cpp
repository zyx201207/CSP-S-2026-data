#include <bits/stdc++.h>
#define int long long
using namespace std;
const int NB=5e5+4,M=5e2+5;
struct node
{
	int subnum,t;
} ;
int c,n,m,d,q,st,en,ans=1e18,w[NB];
vector<node> v[NB];
vector<int> lin[M];
bool vis[NB];
void dfs(int pos,int num,int tot,int pas)
{
	if(pos==en) {
		for(auto i:v[pos]) {
			if(i.subnum==num) {
				ans=min(ans,tot+i.t);
				return ;
			}
		}
	}
	for(auto i:v[pos]) {
		int nsub=i.subnum;
		if(nsub==num) {
			for(auto j:lin[nsub]) {
				if(vis[j]) continue;
				vis[j]=true;
				dfs(j,num,tot,pos);
			}
		} else {
			for(auto j:lin[nsub]) {
				if(j==pos) continue;
				for(auto l:v[j]) {
					if(l.subnum==nsub) {
						if(vis[j]) continue;
						vis[j]=true;
						dfs(j,nsub,tot+i.t+l.t,pos);
					}
				}
			}
		}
	}
	return ;
}
signed main(void)
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++) {
		int kk;
		cin>>kk;
		while(kk--) {
			int aa,tt;
			cin>>aa>>tt;
			v[aa].push_back({i,tt});
			lin[i].push_back(aa);
		}
	}
	while(q--) {
		memset(vis,false,sizeof(vis));
		ans=1e18;
		cin>>st>>en;
		for(auto i:v[st]) {
			vis[st]=true;
			dfs(st,i.subnum,i.t,st);
			vis[st]=false;
		}
		cout<<ans+w[st]+w[en]<<'\n';
	}
	return 0;
} 