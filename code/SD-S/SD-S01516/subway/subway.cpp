#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
int c,n,m,d,q;
int w[500050];
vector<PII>vi[550];
vector<int>vl[500050];
int codd[500050][550];
int bbf[550][500050];
int zbs[500050];
int zd[500050];
void bfs(int u,int coc){
	memset(zd,-1,sizeof zd);
	queue<int>q;
	q.push(u);
	zd[u]=0;
	while(!q.empty()){
		auto op=q.front();
		q.pop();
		zbs[op]++;
		for(auto zz:vl[op]){
			for(auto zx:vi[zz]){
				if(zd[zx.first]==-1 and zbs[zx.first]<d){
					zd[zx.first]=zd[op]+zx.second;
					if(zx.first==coc){
						break;
					}
					q.push(zx.first); 
				}
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		while(k--){
			int xx,yy;
			cin>>xx>>yy;
			vi[i].push_back({xx,yy});
			if(codd[xx][k]==0){
				vl[xx].push_back(k);
				codd[xx][k]=1;
			}
		}
	}
	while(q--){
		int xn,yn;
		cin>>xn>>yn;
		bfs(xn,yn);
		cout<<zd[yn]+w[xn]+w[yn]<<endl;
	}
	return 0;
}
