#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
ll a[2000010],b[2000010];
struct node{
	ll x;
	ll step;
};
ll dist[2000010];
vector<ll> g[2000010];
bool pd(ll x,ll y){
	queue<node> q;
	q.push({x,0});
	int ans=0;
	dist[x]=0;
	while(q.size()){
		node cur=q.front();
		q.pop();
		if(cur.x==y){
			ans++;
			continue;
		}
		for(int i=0;i<g[cur.x].size();i++){
			if(cur.step+1<=dist[g[cur.x][i]]){
				q.push({g[cur.x][i],cur.step+1});
				dist[g[cur.x][i]]=cur.step+1;
			}
		}
	}
	if(ans==2){
		return 1;
	}
	else return 0;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[j]-a[i]>d){
					break;
				}else{
					g[i].push_back(j);
					g[j].push_back(i);
				}
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=1;k<=n;k++){
					dist[k]=2e9;
				}
				if(pd(i,j)){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
		for(int i=1;i<=n;i++){
			while(g[i].size())g[i].pop_back();
		}
	}
	return 0;
}
