#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 505
#define M 500005

int c,n,m,d,q,ans;
int w[M],a[M],t[M],vis[M],f[M];
struct node{
	int w;
	int idx;
};
vector<node> v[M];
queue<int> z;

int Solve(int x,int y){
	z.push(x);
	f[x]=0;
	while(!z.empty()){
		int cur=z.front();
		z.pop();
		if(cur==y){
			return f[cur];
		}
		for(int i=0;i<v[cur].size();++i){
			int j=v[cur][i].idx;
			if(vis[j]) continue;
			f[j]=f[cur]+v[cur][i].w;
			z.push(j);
		}
	}
}

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i){
		cin>>w[i];
	}
	for(int i=1;i<=n;++i){
		int k;
		cin>>k;
		for(int j=1;j<=k;++j){
			cin>>a[j]>>t[j];
		}
		for(int l=1;l<k;++l){
			for(int r=l+1;r<=k;++r){
				v[l].push_back({t[l]+t[r],r});
				v[r].push_back({t[l]+t[r],l});
			}
		}
	}
	for(int i=1;i<=q;++i){
		memset(vis,0,sizeof(vis));
		memset(f,0,sizeof(f));
		while(!z.empty()){
			z.pop();
		}
		int x,y;
		cin>>x>>y;
		ans=w[x]+w[y];
		ans+=Solve(x,y);
		cout<<ans<<'\n';
	}
	return 0;
}
