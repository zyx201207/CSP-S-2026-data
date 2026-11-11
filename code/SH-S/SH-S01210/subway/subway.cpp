#include<bits/stdc++.h>
#define PII pair<int,long long>
using namespace std;
char buf[1<<21],*p1,*p2;
#define gc() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<20,stdin),p1==p2)?0:*p1++)
inline void read(int& x){
	int k=0,f=-1,c=gc();
	for(;!isdigit(c);c=gc())if(c=='-')f=-1;
	for(;isdigit(c);c=gc())k=k*10+(c^48);
	x=k; 
}//Il ne faut pas le faire!!!
//"应当避免对算法常系数的考察"
//——CCF 大纲 
typedef long long ll;
int tot,c,n,m,dd,q;
int w[500005],k[500005];
int metmet[500005][505];
ll d[505][505];
vector<int> met[500005];
vector<PII> g[500505],g1[505];
bool v[500505];
signed main(){
	ios::sync_with_stdio(false);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	read(c),read(n),read(m),read(dd),read(q);
	for(int i=1;i<=m;i++)read(w[i]);
	for(int i=1;i<=n;i++){
		read(k[i]);
		for(int j=1;j<=k[i];j++){
			int a,t;read(a),read(t);
			met[a].push_back(i);
			metmet[a][i]=t;
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			d[i][j]=1e18;
			if(i==j)d[i][j]=0;
		}
	for(int mm=1;mm<=m;mm++)
		for(int k=0;k<met[mm].size();k++){
			int i=met[mm][k];
			for(int t=0;t<met[mm].size();t++){
				int j=met[mm][t];
				if(i==j)continue;
				ll dist=metmet[mm][i]+
						 metmet[mm][j];
				d[i][j]=d[j][i]
				=min(d[i][j],dist);
			}
		}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			for(int k=1;k<=n;k++)
				if(d[i][k]+d[k][j]<d[i][j])
				d[i][j]=d[i][k]+d[k][j];
	while(q--){
		int x,y;read(x),read(y);
		ll ans=w[x]+w[y];
		ll mn=0x3f3f3f3f3f3f3f3f;
		for(int k=0;k<met[x].size();k++){
			int i=met[x][k];
			for(int t=0;t<met[y].size();t++){
				int j=met[y][t];
				mn=min(mn,d[i][j]+
				metmet[x][i]+metmet[y][j]);
			}
		}
		cout<<ans+mn<<"\n";
	}
	return 0;
}
//O(m+n∑k_i+n^2+md^2+n^3+qd^2) 能过吧…… 
