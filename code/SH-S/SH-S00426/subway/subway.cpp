#include<bits/stdc++.h>
using namespace std;
const int N=501,M=5e5+1;
const long long MAX=1e18+1;
int c,n,m,d,q;
long long w[M];
int k[N],cnt[M],x[M][21];
long long y[M][21];
long long wei[N][N],dis[N][N];
struct ii{
	long long weigh;
	int id;
};
vector<ii> xp[N];
bool cmp(ii x,ii y){
	return x.weigh<y.weigh;
}
void dij(int st,int now){
	for(int i=1;i+1<=xp[now].size();i++) if(dis[st][xp[now][i].id]>dis[st][now]+xp[now][i].weigh) dis[st][xp[now][i].id]=dis[st][now]+xp[now][i].weigh,dij(st,xp[now][i].id);
}

int main(){
	cin.tie(0),cout.tie(0);
	std::ios::sync_with_stdio(false);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int j=1;j<=n;j++) for(int k=1;k<=n;k++) if(j!=k) wei[j][k]=MAX;
	for(int i=1;i<=n;i++){
		cin>>k[i];
		int r1,r2;
		for(int j=1;j<=k[i];j++) cin>>r1>>r2,x[r1][++cnt[r1]]=i,y[r1][cnt[r1]]=r2;
	}
	for(int i=1;i<=m;i++) for(int j=1;j<=cnt[i]-1;j++) for(int k=j+1;k<=cnt[i];k++) wei[x[i][j]][x[i][k]]=min(wei[x[i][j]][x[i][k]],y[i][j]+y[i][k]);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) xp[i].push_back((ii){wei[min(i,j)][max(i,j)],j});
		sort(xp[i].begin(),xp[i].end(),cmp);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) if(i!=j) dis[i][j]=MAX;
		dij(i,i);
	}
	while(q--){
		long long minn=MAX;
		int l,r;
		cin>>l>>r;
		for(int i=1;i<=cnt[l];i++) for(int j=1;j<=cnt[r];j++) minn=min(minn,y[l][i]+y[r][j]+dis[x[l][i]][x[r][j]]);
		cout<<minn+w[l]+w[r]<<endl;
	}
	return 0;
}
