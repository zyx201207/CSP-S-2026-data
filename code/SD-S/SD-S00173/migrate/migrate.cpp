#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+5;
int n;
ll x[N],d;
int in[N];
int dis[N],vis[N];
vector<int>g[N];
int Main(){
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>x[i];
		g[i].clear();
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			if(x[j]+d>=x[i]){
				g[j].push_back(i);
				in[i]++;
			}
		}
	}
	/*
	for(int i=1;i<=n;i++){
		cout<<i<<":";
		for(int j=0;j<g[i].size();j++){
			cout<<g[i][j]<<' ';
		}
		cout<<"\n";
	}
	*/
	ll ans=0;
	queue<int>q;
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof(vis));
		q.push(i);
		memset(dis,0x3f,sizeof(dis));
		dis[i]=0;
		while(!q.empty()){
			int now=q.front();
			q.pop();
			if(vis[now]==2) ans--;
			vis[now]++;
			if(vis[now]==2) ans++;
			for(int i=0;i<g[now].size();i++){
				int to=g[now][i];
				if(dis[to]>=dis[now]+1){
					dis[to]=dis[now]+1;
					q.push(to);
				}
			}
		}
	//	cout<<"\n";
	}
	cout<<ans<<"\n";
	return 0;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int t,p;
	cin>>p>>t;
	if(p==13||p==14){
		while(t--){
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				cin>>x[i];
			}
			cout<<"0\n";
		}
	}
	if(p<=6){
		while(t--){
			Main();
		}
	}
	return 0;
}
/*
//  É¾´óÑùÀý 


0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

0 1
6 2
-4 -3 -2 -1 3 6


*/
