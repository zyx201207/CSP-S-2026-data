#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+100,N1=1e3+100,inf=1e15;
struct ti{
	int to;
	int x;
};
int c,n,m,d_,q;
int w[N];
vector<int>v[N1];
vector<int>a[N];
vector<ti>t[N];
int d[N1][N1];
void buid(int x,int y,int w){
	d[x][y]=min(d[x][y],w);
	d[y][x]=min(d[y][x],w);
} 
int find(int x,int y){// 节点x换乘到线路y所需要的时间 
	int l1=t[x].size();
	for(int i=0;i<l1;i++){
		if(t[x][i].to==y)return t[x][i].x;
	}
}
void ini(){
	for(int i=0;i<N1;i++){
		for(int j=0;j<N1;j++){
			d[i][j]=inf;
			if(i==j)d[i][j]=0;
		}
	}
}
void printd(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<d[i][j]<<" ";
		}cout<<"\n";
	}return;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d_,&q);
//	cin>>c>>n>>m>>d_>>q;
	for(int i=1;i<=m;i++)
		scanf("%lld",&w[i]);
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1;j<=k;j++){
			int g,h;
			scanf("%lld%lld",&g,&h);
			a[g].push_back(i);
			t[g].push_back({i,h});
		}
	}
	ini();
	for(int i=1;i<=m;i++){
		for(int j=0;j<a[i].size();j++){
			for(int k=j+1;k<a[i].size();k++){
				int t1=find(i,a[i][j]),t2=find(i,a[i][k]);
//				cout<<i<<" "<<t1<<" "<<t2<<"\n"; 
				buid(a[i][j],a[i][k],t1+t2);
			}
		} 
	} 
//	printd();
	//多源最短路 
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(d[i][j]==0)continue;
			for(int k=1;k<=n;k++){
//				printf("i:%d j:%d k:%d d[i][j]:%d d[i][k]:%d d[j][k]:%d\n",i,j,k,d[i][j],d[i][k],d[j][k]); 
				d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
			}d[j][i]=d[i][j];
		}
	}
//	printd();
	for(int i=1;i<=q;i++){
		int x,y;
		scanf("%lld%lld",&x,&y);
//		cin>>x>>y;
//		cout<<x<<" "<<y<<"******\n";
		int ans=inf; 
		for(int j=0;j<a[x].size();j++){
			for(int k=0;k<a[y].size();k++){
				int ts=find(x,a[x][j])+find(y,a[y][k]);
				ans=min(ans,d[a[x][j]][a[y][k]]+ts);
			} 
		}
//		printf("ans:%d w[x]:%d w[y]:%d\n",ans,w[x],w[y]);
		cout<<ans+w[x]+w[y]<<"\n";
	}
	return 0;
}
