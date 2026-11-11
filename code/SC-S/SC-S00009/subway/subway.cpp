#include<bits/stdc++.h>
using namespace std;
const int N=5e5+510;
long long s[N],w[N],dis[510][510];
int cc[21],c1[21],c2[21];
unordered_map<int,int> g[N];
unordered_map<int,bool> link[N];
queue<int> q;
int main(){
	ios::sync_with_stdio(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	memset(dis,0x3f,sizeof(dis));
	int c,n,m,d,T;
	cin>>c>>n>>m>>d>>T;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,tt;
			cin>>a>>tt;
			link[a][i]=1;
			g[a][i]=tt;}}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(i==j) dis[i][j]=0;
	for(int i=1;i<=m;i++){
		int p=0;
		for(auto j:g[i])
			cc[++p]=j.first;
		for(int j=1;j<=p;j++)
			for(int k=j+1;k<=p;k++){
				int cj=min(cc[j],cc[k]),ck=max(cc[j],cc[k]);
				if(link[i][cj]&&link[i][ck]) dis[cj][ck]=min(dis[cj][ck],(long long)(g[i][cj]+g[i][ck]));}}
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			for(int k=1;k<=n;k++){
				if(j==k||k==i) continue;
				dis[i][j]=min(dis[i][j],dis[min(i,k)][max(i,k)]+dis[min(j,k)][max(j,k)]);}
	while(T--){
		memset(c1,0,sizeof(c1));
		memset(c2,0,sizeof(c2));
		int l,r;
		long long ans=1e18;
		cin>>l>>r;
		int p1=0,p2=0;
		for(auto j:g[l])
			c1[++p1]=j.first;
		for(auto j:g[r])
			c2[++p2]=j.first;
		for(int j=1;j<=p1;j++)
			for(int k=1;k<=p2;k++){
				int cj=min(c1[j],c2[k]),ck=max(c1[j],c2[k]);
				if(link[r][cj]&&link[l][ck]) swap(l,r);
				ans=min(ans,dis[cj][ck]+(long long)g[l][cj]+(long long)g[r][ck]);}
		cout<<ans+w[l]+w[r]<<"\n";}
}
