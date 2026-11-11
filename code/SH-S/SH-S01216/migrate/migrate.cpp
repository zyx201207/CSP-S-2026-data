#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll c,t,n,d,a[2000010],vis[2000010];
bool ans[2000010];
queue <ll> q;
void bfs(ll s){
	for (int i=1;i<=n;i++)  vis[i]=4e18;
	vis[s]=0;
	q.push(s);
	while (!q.empty()){
		ll u=q.front();
		q.pop();
		for (int v=u+1;v<=n && a[v]-a[u]<=d;v++){
			if (vis[v]==4e18){
				vis[v]=vis[u]+1;
				q.push(v);
			}else if (vis[u]+1==vis[v])  ans[v]=(!ans[v]);
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>t;
	while (t--){
		cin>>n>>d;
		for (int i=1;i<=n;i++)  cin>>a[i];
		ll res=0;
		for (int i=1;i<=n;i++){
			for (int i=1;i<=n;i++)  ans[i]=0;
			bfs(i);
			for (int j=1;j<=n;j++)  res+=ans[j];
		}
		cout<<res<<"\n";
	}
	return 0;
} 
