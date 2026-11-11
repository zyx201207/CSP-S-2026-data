#include<bits/stdc++.h>
using namespace std;
const int M=5e5+5;
const int N=505;
int c,n,m,d,q;
int w[M]; 
int k[N];
vector<pair<int,int>>g[N]; 
vector<int>un[N];
vector<int>a[N];
vector<int>t[N];
int dis[N];
int A,T;
vector<pair<int,int>>ma[N]; 
bool inq[N];
void dij(int s){
	memset(dis,0x3f3f3f3f,sizeof(dis));
	memset(inq,0,sizeof(inq));
	queue<pair<int,int>>q;
	q.push({s,0});
	dis[s]=0;
	inq[s]=1;
	while(!q.empty()){
		auto u=q.front();
		inq[u.first]=0;
		q.pop();
		for(auto t:g[u.first]){
		    int v=t.first;
		    int w=t.second;
			if(dis[v]>dis[u.first]+w){
				dis[v]=dis[u.first]+w;
				if(inq[v]=0)
				q.push({v,dis[v]}); 
			}
		}
	}
	return;
}
int query(int x,int y){
	dij(x);
	return dis[y]+w[x]+w[y];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout); 
	cin>>c>>n>>m>>d>>q;
 
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	if(d==2){
		for(int i=1;i<=n;i++){
			cin>>k[i];
			a[i].push_back(0);
			t[i].push_back(0);
			for(int i=1;i<=2;i++){
			cin>>A>>T;
			a[i].push_back(A);
			t[i].push_back(T);
		    }
		}
	while(q--){
		int x,y;cin>>x>>y;
		int ans=0;
		ans+=w[x];
		ans+=w[y];
		for(int i=1;i<=n;i++){
			ans+=a[i][1];
			ans+=a[i][2];
		}
		cout<<ans<<endl;
	}
	}else{
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>A>>T;
			a[i].push_back(A);
			t[i].push_back(T);
			un[i].push_back(A);
		}
		for(int u:un[i]){
			for(int v:un[i]){
				if(u!=v){
					g[u].push_back({v,2*T});
				}
			}
		}
	}
	
	while(q--){
		int x,y;cin>>x>>y;
		cout<<query(x,y)<<endl;
	}
    }
	return 0;
} 
