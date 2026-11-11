#include<bits/stdc++.h>
using namespace std;
//#define int long long
struct asd{
	int u,v;
	bool operator<(const asd &aaa)const{
		return v>aaa.v;
	}
	
};

int qwe,n,m,d,r;
int x,y;
int k;

int c[20005][20005];
vector<asd> li[100005];
vector<int> node[100005];
int v[100005];
int dj(int x,int y){
	int w[100005];
	bool l[100005];
	for(int i=1;i<=m;i++){
		w[i]=2e9;
		l[i]=0; 
	} 
//	cout<<1;
	w[x]=0;
	priority_queue<asd> q;
	q.push({x,0});
//	cout<<1;
	while(q.size()){
//		cout<<1;
		asd t=q.top();
		q.pop();
		int u=t.u;
		if(l[u]==1){
			continue;
		}
		l[u]=1;
		asd p;
		for(int i=0;i<node[u].size();i++){
			int uu=node[u][i];
			for(int j=0;j<li[uu].size();j++){
				asd tt=li[uu][j];
				if(tt.u==u){
					p=tt;
					break;
				}
			} 
			for(int j=0;j<li[uu].size();j++){
				asd tt=li[uu][j];
				if(tt.u==u){
					continue;
				}
				int uuu=tt.u;
				int www=tt.v;
				if(w[uuu]>w[u]+www+p.v){
					w[uuu]=w[u]+www+p.v;
					q.push({uuu,w[uuu]});
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		c[x][i]=w[i];
	}
	c[y][x]=w[y];
	return w[y];
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>qwe>>n>>m>>d>>r;
	
	for(int i=1;i<=m;i++){
		cin>>v[i];
		for(int j=1;j<=m;j++){
			c[i][j]=2e9;
		} 
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>x>>y;
			li[i].push_back({x,y});
			node[x].push_back(i);
			
		}
	}
	for(int i=1;i<=r;i++){
		cin>>x>>y;
//		cout<<1;
		int ans;
		if(c[x][y]==2e9){
			ans=dj(x,y);
		}else{
			ans=c[x][y];
		} 
		cout<<ans+v[x]+v[y]<<"\n";
	}
}

