#include<bits/stdc++.h>
using namespace std;
const int N=2e4+1;
int c,n,m,d,q;
int v[N][2002];
int a[N];
int uv[N],tii[N];
int sum[N];
bool vis[N];
int ans;

int g;
void bfs(int l,int r,int tt) {
	queue<pair<int,int> > s;
	s.push({l,0});
	vis[l]=1;
	pair<int,int>t;
	while(!s.empty()) {
		t=s.front();
		s.pop();
		if(t.first==r) {
			ans=min(t.second,ans);
			continue;
		}
		for(int j=1; j<=g; j++) {
			if(vis[j]==1) {	
				continue;
			}
			if(v[t.first][j]==0) {
				continue;
			}
			s.push({j,t.second+v[t.first][j]});
			vis[t.first]=1;
		}
	}
}
int main() {
//	freopen("subway.in","r",stdin);
//	freopen("subway.out","w",stdout);

	cin>>c>>n>>m>>d>>q;
	for(int i=1; i<=m; i++) {
		cin>>a[i];
	}
	for(int i=1; i<=n; i++) {
		int k;
		cin>>k;
		for(int j=1; j<=k; j++) {
			cin>>uv[j]>>tii[j];
			g=max(g,uv[j]);
		}
		for(int j=1; j<=k; j++) {
			for(int ll=j+1; ll<=k; ll++) {
				v[uv[j]][uv[ll]]=tii[j]+tii[ll];
				v[uv[ll]][uv[j]]=tii[j]+tii[ll];
			}
		}
	}
	for(int i=1; i<=q; i++) {
		int l,r;
		cin>>l>>r;
		ans=1e9;
		memset(vis,0,sizeof(vis));
		bfs(l,r,0);
		cout<<(ans+a[l]+a[r])<<endl;
	}

	return 0;
}
