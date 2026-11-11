#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m,c,qt,d,w[N],ans,f[N],v[N][501];
struct line{
	int x,t;
};
vector<line>sub[N];
vector<line>sta[501];
struct node{
	int x,t,i;
};
queue<node>q;
void bfs(int x){
	for(int i=0;i<sub[x].size();i++){
		q.push({x,sub[x][i].t,sub[x][i].x});
	}
	while(q.size()){
		int kx=q.front().x,kt=q.front().t,ki=q.front().i;
		q.pop();
		if(v[kx][ki]>kt){
			v[kx][ki]=kt;
		}
		else{
			continue;
		}
		for(int i=0;i<sta[ki].size();i++){
			q.push({sta[ki][i].x,kt+sta[ki][i].t,ki});
		}
		if(kx!=x){
			for(int i=0;i<sub[kx].size();i++){
				if(sub[kx][i].x!=ki){
					q.push({kx,kt+sub[kx][i].t,sub[kx][i].x});
					//cout<<kx<<" "<<kt+sub[kx][sta[kx][i]]<<" "<<sta[kx][i]<<endl;
				}
			}
		}
	}
	
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(v,127,sizeof v);
	cin>>c>>n>>m>>d>>qt;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int t,x;
			cin>>x>>t;
			sta[i].push_back({x,t});
			sub[x].push_back({i,t});
		}
	}
	bfs(1);
	for(int i=1;i<=m;i++){
		f[i]=2147483647;
		for(int j=1;j<=n;j++){
			f[i]=min(f[i],v[i][j]);
			//cout<<v[i][j]<<" ";
		}
		//cout<<endl;
	}
	f[1]=0;
	while(qt--){
		int x,y;
		cin>>x>>y;
		if(f[x]<f[y]){
			cout<<f[y]-f[x]+w[x]+w[y]<<endl;
		}
		else{
			cout<<f[x]-f[y]+w[x]+w[y]<<endl;
		}
	}
	return 0;
}