#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int m,n,c,dd,qq;
struct st{
	int v,w;
};
vector<st>g[500010];
int a[500010],d[500010];
bool b[500010];
const int N=500000;
void spfa(int start){
	memset(d,0x3f,sizeof d);
	queue<int>q;
	q.push(start);
	d[start]=0;
	b[start]=1;
	while(!q.empty()){
		int now=q.front();
		q.pop();
		b[now]=0;
		for(auto e:g[now]){
			if(d[e.v]<=d[now]+e.w){
				d[e.v]=d[now]+e.w;
				if(b[e.v]){
					q.push(e.v);
					b[e.v]=1;
				}
			}
		}
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>m>>n>>dd>>qq;
	for(int i=1;i<=m;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int aaaa,v,w;
			cin>>v>>w;
			g[v].push_back({v+N,w});
			g[v+N].push_back({v,w});
		}
	}
	for(int i=1;i<=qq;i++){
		int s,e;
		cin>>s>>e;
		spfa(s);
		cout<<d[e]+a[s]+a[e];
	}
	return 0; 
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
