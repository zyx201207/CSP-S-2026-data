#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,Q,k;
const int N=5e5+10;
int w[N];
struct node{
	int a;
	long long t;
	bool operator <(const node f)const{
		return t<f.t;
	}
};
long long used[N];
priority_queue<node>q;
vector<node>head[N],hd[N];
long long anser(int x,int y){
	memset(used,0x7f,sizeof used);
	used[x]=0;
	q.push({x,0});
	while(!q.empty()){
		node u=q.top();
		q.pop();
		for(int i=0;i<hd[u.a].size();i++){
			for(int j=0;j<head[hd[u.a][i].a].size();j++){
				node v=u;
				v.a=head[hd[u.a][i].a][j].a;
				v.t+=hd[u.a][i].t+head[hd[u.a][i].a][j].t;
				if(used[v.a]>v.t){
					used[v.a]=v.t;
					q.push({v.a,v.t});
				}
			}
		}
	}
	return used[y]+w[x]+w[y];
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
		cin>>k;
		for(int j=1;j<=k;j++){
			int x,y;
			cin>>x>>y;
			hd[x].push_back({i,y});
			head[i].push_back({x,y});	
		}
	}
	while(Q--){
		int x,y;
		cin>>x>>y;
		cout<<anser(x,y)<<"\n";
	}
}
