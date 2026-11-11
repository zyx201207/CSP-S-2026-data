#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;
const int N=510,N1=1e5+5;
vector<int> a[N1],t[N1],mp[N1],mm[N1];
int x[N1],y[N1],f[N1],w[N];
void bfs(int x,int y){
	queue<pair<int,int> > q;
	q.push({x,mp[x][0]});
	f[x]+=w[x];
	int xl=mp[x][0];
	while(!q.empty()){
		pair<int,int> p=q.front();
		q.pop(); 
		f[p.fi]+=t[p.se][p.fi];
		cout<<f[p.fi]<<" ";
		if(p.fi==x){
			f[p.fi]+=w[p.fi];
			break;
		}
		for(auto it:mm[p.fi]){
			cout<<it<<" ";
			for(auto ii:mp[it]){
				q.push({it,mp[it][ii]});
			}
			
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int c,n,m,d,q;cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	} 
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1;j<=k;j++){
			int x,y;cin>>x>>y;
			a[i].push_back(x),t[i].push_back(y);
			mp[x].push_back(i);//mp有几条线路 
		}
		for(int j=1;j<k;j++){
			mm[a[i][j-1]].push_back(a[i][j]);
		}
	}
	while(q--){
		int x,y;cin>>x>>y;
		bfs(x,y);
		cout<<f[y]<<'\n';
	}
	return 0;
}


