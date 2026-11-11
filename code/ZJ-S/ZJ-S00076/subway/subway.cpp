#include<iostream>
#include<vector>
#include<cstring>
#define int long long
using namespace std;
typedef pair<int,int> pii;
const int N=510,M=500010,INF=1e18;
int n,m,q,a[M],g[N][N],f[N][N];
vector<pii> sta[M];
inline int read(){
	char c=getchar();
	int num=0,op=1;
	while(c<'0'||c>'9'){
		if(c=='-')
			op=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
		num=num*10+c-'0',c=getchar();
	return num*op;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	n=read(),n=read(),m=read(),q=read(),q=read();
	for(int i=1;i<=m;i++)
		a[i]=read();
	for(int i=1;i<=n;i++){
		int k=read();
		for(int j=1;j<=k;j++){
			int a=read(),b=read();
			sta[a].push_back(make_pair(i,b));
		}
	}
	memset(g,0x3f,sizeof g),memset(f,0x3f,sizeof f);
	for(int i=1;i<=n;i++)
		g[i][i]=f[i][i]=0;
	for(int i=1;i<=m;i++){
		for(int j=0;j<sta[i].size();j++){
			for(int k=j+1;k<sta[i].size();k++){
				int from=sta[i][j].first,to=sta[i][k].first;
				g[from][to]=g[to][from]=min(g[from][to],sta[i][j].second+sta[i][k].second);
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++)
//			cout<<g[i][j]<<' ';
//		cout<<endl;
//	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			f[i][j]=g[i][j];
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++)
//			cout<<(f[i][j]>(int)1e9?-1:f[i][j])<<' ';
//		cout<<endl;
//	}
	while(q--){
		int x=read(),y=read(),ans=INF;
		for(int i=0;i<sta[x].size();i++){
			for(int j=0;j<sta[y].size();j++){
//				cout<<sta[x][i].first<<' '<<sta[y][j].first<<endl;
				ans=min(ans,f[sta[x][i].first][sta[y][j].first]+sta[x][i].second+sta[y][j].second);
			}
		}
		printf("%lld\n",ans+a[x]+a[y]);
	}
}
