#include <bits/stdc++.h>
using namespace std;

struct node{
	int I,t;
};

int w[80005];node p[505][80005];// 每个站的地铁口走到站厅的时间；第i条线经过的地铁站 
int k[505];bool f[80005];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;// 测试点编号，地铁线路数，地铁站数，每个地铁站最多被几条线路经过，出行计划数 
	cin>>c>>n>>m>>d>>q;
	
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	
	vector<node> a[80005];
	
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>p[i][j].I>>p[i][j].t;
		}
		for(int j=1;j<=k[i];j++){
			for(int h=j+1;h<=k[i];h++){
				a[j].push_back({p[i][h].I,p[i][h].t+p[i][j].t});
				a[h].push_back({p[i][j].I,p[i][h].t+p[i][j].t});
			}
		}
	}
	while(q--){
		memset(f,false,sizeof(f));
		int x,y,ans=0;
		cin>>x>>y;
		ans=ans+w[x]+w[y];
		queue<node> q;
		q.push({x,0});
		f[x]=true;
		while(!q.empty()){
			node top=q.front();
			q.pop();
			if(top.I==y){
				cout<<top.t+ans<<"\n";
				break;
			}
			for(int i=0;i<a[top.I].size();i++){
				if(f[a[top.I][i].I]==false){
					q.push({a[top.I][i].I,top.t+a[top.I][i].t});
					f[a[top.I][i].I]=true;
				}
			}
		}
	}
	return 0;
}
