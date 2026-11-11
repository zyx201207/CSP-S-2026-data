#include<bits/stdc++.h>
#define IO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define int long long
using namespace std;
const int N=505,M=5e5+5,inf=1e18;
struct node{
	int v,w;
	bool operator <(const node& o) const{
		return v<o.v;
	}
};
int c,n,m,d,q,w[M],dis[N][N],l,r,ans;
vector<node> a[N],b[M];
inline int check(int pos,int x){
	int l=0,r=a[pos].size()-1;
	while(l<=r){
		int mid=(l+r)>>1;
		if(a[pos][mid].v==x) return mid;
		if(a[pos][mid].v<x){
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	return -1;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	IO;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1,x;i<=n;i++){
		cin>>x;
		for(int j=1,sta,t;j<=x;j++){
			cin>>sta>>t;
			a[i].push_back({sta,t});
			b[sta].push_back({i,t});
		}
		sort(a[i].begin(),a[i].end());
	}
	memset(dis,0x3f,sizeof dis);
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			int minn=inf;
			for(int k=0;k<(int)a[i].size();k++){
				int l=check(j,a[i][k].v);
				if(l==-1) continue;
				minn=min(minn,a[i][k].w+a[j][l].w);
			}
			dis[i][j]=minn,dis[j][i]=minn;
		}
	}
	for(int i=1;i<=n;i++) dis[i][i]=0;
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	while(q--){
		cin>>l>>r;
		ans=inf;
		for(int i=0;i<(int)b[l].size();i++){
			for(int j=0;j<(int)b[r].size();j++){
				int u=b[l][i].v,v=b[r][j].v;
				ans=min(ans,b[l][i].w+dis[u][v]+b[r][j].w);
			}
		}
		cout<<w[l]+ans+w[r]<<'\n';
	}

	return 0;
}

