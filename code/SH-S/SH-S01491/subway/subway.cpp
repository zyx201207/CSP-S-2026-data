#include<bits/stdc++.h>
using namespace std;
const int N=5e5,INF=1e9;
int c,n,m,d,q;
int w[N],k[505];
vector<int> a[505];
vector<long long> t[505];
int st[N],ed[N];
bool f[505][505];
long long dis[505][505];
void solve1(){
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			dis[i][j]=INF;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k[i];j++){
			for(int r=1;r<j;r++){
				f[a[i][j]][a[i][r]]=f[a[i][r]][a[i][j]]=1;
				dis[a[i][j]][a[i][r]]=min(dis[a[i][j]][a[i][r]],t[i][j]+t[i][r]);
				dis[a[i][r]][a[i][j]]=min(dis[a[i][r]][a[i][j]],t[i][j]+t[i][r]);
			}
		}
	} 
	for(int i=1;i<=m;i++){
		for(int p=1;p<=m;p++){
			for(int j=1;j<=m;j++){
				if(f[i][p]&&f[p][j]){
					dis[i][j]=min(dis[i][j],dis[i][p]+dis[p][j]);
					f[i][j]=true;
				}
			}
		}
	}
	for(int i=1;i<=q;i++){
		long long ans=w[st[i]]+w[ed[i]]+dis[st[i]][ed[i]];
		cout<<ans<<"\n";
	}
}
long long T;
map<int,int> line[505];
void solve2(){
	T=t[1][1];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dis[i][j]=INF;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k[i];j++){
			for(int p=1;p<=n;p++){
				if(p==i)continue;
				if(line[p][a[i][j]]){
					f[i][p]=f[p][i]=1;
					dis[i][p]=dis[p][i]=2*T;
				}
			}
		}
	} 
	for(int i=1;i<=n;i++){
		for(int p=1;p<=n;p++){
			for(int j=1;j<=n;j++){
				if(f[i][p]&&f[p][j]){
					dis[i][j]=min(dis[i][j],dis[i][p]+dis[p][j]);
					f[i][j]=true;
				}
			}
		}
	}
	for(int i=1;i<=q;i++){
		long long ans=w[st[i]]+w[ed[i]]+dis[st[i]][ed[i]];
		cout<<ans<<"\n";
	}
}
struct node{
	int to;
	long long w;
	bool operator< (const node&o)const{
		return w>o.w;
	}
};
/*void solve3(){
	vector<node> edge[1005];
	long long dist[1005];
	for(int i=1;i<=m;i++){
		dist[i]=INF;
	}
	for(int i=1;i<=n;i++){
		if(k[i]<=1)continue;
		e[a[i][1]].push_back({a[i][2],t[i][1]+t[i][2]});
		e[a[i][2]].push_back({a[i][1],t[i][1]+t[i][2]});
	} 
	for(int i=1;i<=q;i++){
		dist[st[i]]=0;
		priority_queue<node> kp;
		q.push({st[i],0});
		while(!q.empty()){
			int u=q.top();
		}
	}
}*/
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		a[i].push_back(-1);
		t[i].push_back(-1);
		for(int j=1;j<=k[i];j++){
			int a1,t1;
			cin>>a1>>t1;
			a[i].push_back(a1);
			t[i].push_back(t1);
			line[i][a[i][j]]=1;
		}
	} 
	for(int i=1;i<=q;i++){
		cin>>st[i]>>ed[i];
	}
	if(c<=8){
		solve1();
	}
	else if(12<=c&&c<=19){
		solve2();
	}
	return 0;
} 
