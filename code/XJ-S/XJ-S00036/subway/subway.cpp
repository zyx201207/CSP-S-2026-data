#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,D,Q;
int w[500005];
int k[500005];
vector<int>a[500005];
vector<int>t[500005];
int d[500005];
int S,T;
struct road{
	int v,len;
};
vector<road>mp[500005];
struct node{
	int x,len;
	bool friend operator<(node k , node l){
		return k.len>l.len;
	}
};
void dijistra(){
	memset(d,0x3f3f,sizeof(d));
	priority_queue<node>q;
	q.push({S,0});
	d[S]=0;
	while(q.size()){
		node r=q.top();
		q.pop();
		if(r.len!=d[r.x])continue;
		for(int i=0;i<mp[r.x].size();i++){
			if(d[mp[r.x][i].v]>r.len+mp[r.x][i].len){
				d[mp[r.x][i].v]=r.len+mp[r.x][i].len;
				q.push({mp[r.x][i].v , d[mp[r.x][i].v]});
			}
		}
	}
	return;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>c>>n>>m>>D>>Q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		int ak,tk;
		for(int j=1;j<=k[i];j++){
			cin>>ak>>tk;
			a[i].push_back(ak);
			t[i].push_back(tk);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<k[i];j++){
			for(int v=j+1;v<k[i];v++){
				mp[a[i][j]].push_back({a[i][v],t[i][j]+t[i][v]});
				mp[a[i][v]].push_back({a[i][j],t[i][j]+t[i][v]});
			}
		}
	}
	while(Q--){
		cin>>S>>T;
		dijistra();
		cout<<d[T]+w[S]+w[T]<<"\n";
	}
	return 0;
}
