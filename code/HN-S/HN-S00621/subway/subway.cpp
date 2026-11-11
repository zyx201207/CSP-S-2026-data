#include<bits/stdc++.h>
using namespace std;
using pai=pair<int,pair<int,int>>;
const int N=505,M=2e4+5;
int n,w[M],c,m,d,p,k[N];
int b[N][M],t[N][M],v[N];
vector<int> e[M],a[N][M];
void bfs(int u ,int u2){
	for(int i=1;i<=m;i++)v[m]=0;
	queue<pai> h;
	v[u]=w[u];
	h.push({u,{w[u],0}});
	while(h.size()){
		pai tt=h.front();
		h.pop();
		int t1=tt.first,t2=tt.second.first,t3=tt.second.second;
		for(auto x:e[t1]){
			for(auto y:a[x][t1]){
//				cout<<t1<<" "<<x<<" "<<y<<" "<<v[y]<<""<<a[1][1].size()<<"\n";
				if(!v[y]||v[y]>t2+t[x][y]){
					v[y]+=(t[x][y]+t2);
					if(!t3)v[y]+=t[x][t1];
					else if(t1!=x)v[y]+=t[x][t1];
					h.push({y,{v[y],x}});	
				}
			}
		}
	}
//	for(int i=1;i<=m;i++)cout<<v[i]<<" ";
	cout<<v[u2]<<"\n";
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int aa,dd;
			cin>>aa>>dd;
			b[i][j]=aa,t[i][aa]=dd;
			e[b[i][j]].push_back(i);
			if(j!=1){
				a[i][b[i][j]].push_back(b[i][j-1]);
				a[i][b[i][j-1]].push_back(b[i][j]);
			}
		}
	}
	while(p--){
		int x,y;
		cin>>x>>y;
		bfs(x,y);
	}
	return 0;
}

