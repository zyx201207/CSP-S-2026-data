#include<bits/stdc++.h> 
using namespace std;
#define int long long
const int N=500+5,M=3e3+5;
int c,m,n,d,p;//c-测试点编号
//d每个地铁站最多被几条线路经过，p出行计划数 
int w[M],dis[M][M];
int a[M],t[M];
int cnt=0,head[M];
struct ed{
	int from,next,to,wi;
}bian[M*2];
void add(int a,int b,int c){
	bian[++cnt].from=a;
	bian[cnt].to=b;
	bian[cnt].next=head[a];
	bian[cnt].wi=c;
	head[a]=cnt;	
}
queue<int> qq;
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[j]>>t[j];
		}
		for(int j=1;j<k;j++){
			for(int q=j+1;q<=k;q++){
				add(a[j],a[q],t[j]+t[q]);
				add(a[q],a[j],t[j]+t[q]);
			}
		}
	}
	memset(dis,1,sizeof(dis));
	for(int i=1;i<=m;i++){
		qq.push(i);
		dis[i][i]=0;
		while(!qq.empty()){
			int f=qq.front();
			qq.pop();
			for(int e=head[f];e;e=bian[e].next){
				int tt=bian[e].to;
				if(dis[i][tt]>bian[e].wi+dis[i][f]){
					dis[i][tt]=bian[e].wi+dis[i][f];
					qq.push(tt);
				}
			}
		}
	}
	for(int i=1;i<=p;i++){
		int r,l;
		cin>>r>>l;
		cout<<dis[r][l]+w[r]+w[l]<<endl;
	}
	
	
	return 0;
}
//44
/*
从地铁口走进去要那么久吗？ 
*/