#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=5e5+5;
int n,m,q,x,y,k,qe;
map<pair<int,int>,int> t;
int w[N],d[N];
vector<pair<int,int> >v[N];
void bfs(int x){
	queue<pair<int,int> > q;
	q.push({x,0});
	while(!q.empty()){
		pair<int,int> rt=q.front();
		int x=rt.first,i=rt.second;
		q.pop();
		for(auto rt:v[x]){
			int to=rt.first,j=rt.second;
			int k=0;
			if(i!=j&&x<=m){
				k=t[{x,i}]+t[{x,j}];
			}
			if(to==qe){
				k=t[{to,j}];
			}
			if(d[x]+k<d[to]){
				d[to]=d[x]+k;
				q.push({to,j});
			}
		}
	}
}
void maind(){
	cin>>n>>n>>m>>q>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>x>>y;
			v[x].push_back({i+m,i});
			v[i+m].push_back({x,i});
			t[{x,i}]=y;
		}
	}
	while(q--){
		int s,t;
		cin>>s>>t;
		qe=t;
		memset(d,0x3f,sizeof(d));
		d[s]=0;
		bfs(s);
		printf("%d\n",d[t]+w[s]+w[t]);
	}	
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int T=1;
	//cin>>T;
	while(T--){
		maind();
	}
	return 0;
}

