#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pi pair<int,int>
const int N=5e5+5;
int c,n,m,d,qu,w[N],k[505];
vector<vector<int> > v(N),a(505),t(505);
priority_queue<pi,vector<pi>,greater<pi> > q; 
int fs(int z,int mu){
	while(!q.empty()) q.pop();
	q.emplace(0,z);
	int f,s,u,wo;
	bool b[N]={},bb[505]={};
	b[z]=1;
	while(!q.empty()){
		f=q.top().first;
		s=q.top().second;
		q.pop();
		if(s==mu) return f;
		for(int& i:v[s]){
			if(bb[i]) continue;
			bb[i]=1;
			for(int j=1;j<=k[i];++j){
				if(a[i][j]==s){
					wo=j;
					break;
				}
			}
			for(int j=1;j<=k[i];++j){
				u=a[i][j];
				if(!b[u]){
					q.emplace(t[i][wo]+t[i][j]+f,u);
					b[u]=1;
				}
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>n>>m>>d>>qu;
	for(int i=1;i<=m;++i){
		cin>>w[i];
	}
	int z,g;
	for(int i=1;i<=n;++i){
		cin>>k[i];
		a[i].push_back(0);
		t[i].push_back(0);
		for(int j=1;j<=k[i];++j){
			cin>>z>>g;
			a[i].push_back(z);
			t[i].push_back(g);
			v[z].push_back(i);
		}
	}
	
	
	for(int i=1;i<=qu;++i){
		cin>>z>>g;
		cout<<fs(z,g)+w[z]+w[g]<<'\n';
	}
	return 0;
}