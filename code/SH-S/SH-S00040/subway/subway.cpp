#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q,a[500001],x,y;
int k[501],p2[500001],p[500001],tot,ans[501][501],dist[501][501];
struct node{
	int l,r;
};
vector<node> s[501];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > qq;
int dis[501],vis[501];
void dij(int x){
	for(int i=1;i<=n;i++) dis[i]=1e18,vis[i]=0;
	dis[x]=0;
	qq.push(make_pair(0,x));
	while(!qq.empty()){
		int tp=qq.top().second;
		qq.pop();
		if(vis[tp]) continue;
		vis[tp]=1;
		for(int i=0;i<s[tp].size();i++){
			int j1=s[tp][i].l;
			int j2=s[tp][i].r;
			if(dis[j1]>dis[tp]+j2){
				dis[j1]=dis[tp]+j2;
				qq.push(make_pair(dis[j1],j1));
			}
		}
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>x>>y;
			p[++tot]=x;
			p2[tot]=y;
		}
		k[i]+=k[i-1];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			node r;
			r.l=j;
			r.r=1e18;
			for(int l=k[i-1]+1;l<=k[i];l++){
				for(int ll=k[j-1]+1;ll<=k[j];ll++){
					if(p[l]==p[ll]){
						r.r=min(r.r,p2[l]+p2[ll]);
					}
				}
			}
			s[i].push_back(r);
			r.l=i;
			s[j].push_back(r);
		}
	}
	for(int i=1;i<=n;i++){
		dij(i);
		for(int j=1;j<=n;j++) dist[i][j]=dis[j];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int l=k[i-1]+1;l<=k[i];l++){
				for(int ll=k[j-1]+1;ll<=k[j];ll++){
					if(ans[p[l]][p[ll]]==0) ans[p[l]][p[ll]]=dist[i][j]+p2[l]+p2[ll];
					else ans[p[l]][p[ll]]=min(dist[i][j]+p2[l]+p2[ll],ans[p[l]][p[ll]]);
				}
			}
		}
	}
	while(q--){
		cin>>x>>y;
		int lll=ans[x][y];
		int rrr=ans[y][x];
		if(lll==0) lll=rrr;
		if(rrr==0) rrr=lll;
		cout<<min(lll,rrr)+a[x]+a[y]<<"\n";
	}
	return 0;
}
