#include<bits/stdc++.h> 
using namespace std;
typedef pair<int,int> PI;
const int M=5e5+10,N=505;
int c,n,m,d,Q,w[M],x,y,sn[N],xx,yy,k;//sn代表每条的站数,xx,yy表示查询编号 
vector<int> a[N],T[N],z[M];
vector<PI> points[M];
map<int,int> pre,dis;
map<int,bool> f;
priority_queue<PI,vector<PI>,greater<PI>> q;
struct T{
	int to,len,next;
}e[M*6];
void add(int u,int v,int len){
	e[++k]={v,len,pre[u]};
	pre[u]=k;
}
void dij(int st,int ed){
	f.clear();
	for(int i=1;i<=n;i++){
		int t=a[i].size();
		for(int j=0;j<t;j++){
			dis[a[i][j]]=0x3f3f3f3f;
		}
	}
	for(int i=1;i<=m;i++){
		dis[i+m]=0x3f3f3f3f;
	}
	dis[st]=0;
	while(q.size()) q.pop();
	q.push({0,st});
	while(!q.empty()){
		int dt=q.top().first,h=q.top().second;
		q.pop();
		if(f.count(h)) continue;
		f[h]=1;
		if(h==ed){
			int total=dis[ed]+w[st-m]+w[ed-m];
			cout<<total<<"\n";
			return;
		}
		for(int i=pre[h];i;i=e[i].next){
			int to=e[i].to,len=e[i].len,nowdis=dis[to];
			if(!f.count(to)&&dt+len<nowdis){
				dis[to]=dt+len;
				q.push({dis[to],to});
			}
		}
	}
}
int decode(int x){
	if(x>=2000000) return x%2000000;
	else return x;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>Q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>sn[i];
		for(int j=1;j<=sn[i];j++){
			cin>>x>>y;
			a[i].push_back(x);
			T[i].push_back(y);
			z[x].push_back(i);
			points[x].push_back({i,j});
		} 
	}
	for(int i=1;i<=m;i++){
		int t=z[i].size();
		if(t>1){
			for(int j=0;j<t;j++){
				int xxx=points[i][j].first,yyy=points[i][j].second;
				a[xxx][yyy-1]=z[i][j]*2000000+i;//换乘站重新编号 
			}
		}
	}
	for(int i=1;i<=n;i++){
		int t=a[i].size();
		for(int j=0;j<t-1;j++){
			add(a[i][j],a[i][j+1],0);//地铁连接
			add(a[i][j+1],a[i][j],0);
		}
	} 
	for(int i=1;i<=n;i++){
		int t=a[i].size();
		for(int j=0;j<t;j++){
			int ting=decode(a[i][j])+m;
			add(a[i][j],ting,T[i][j]);//连接站厅 
			add(ting,a[i][j],T[i][j]);
		}
	}
	for(int i=1;i<=Q;i++){
		cin>>xx>>yy;
		dij(xx+m,yy+m);
	} 
	return 0;
}
