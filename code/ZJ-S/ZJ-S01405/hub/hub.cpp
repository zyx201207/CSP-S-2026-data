#include<bits/stdc++.h>
using namespace std;
long long int C,T,n,k,vis[51],v[51],ans=1e9,mx;
vector<int> a[51];
void dfs(int u){
	//cout<<u<<endl;
	v[u]=1;
	for(int i:a[u]){
		if(v[i]==0&&vis[i]==1){
			dfs(i);
		}
	}
	return;
}
void b(int u){
	queue<int> p;
	p.push(u);
	memset(v,0,sizeof(v));
	v[u]=1;
	while(!p.empty()){
		int x=p.front();
		p.pop();
		if(vis[x]==1){
			if(v[x]-1>mx){
				mx=v[x]-1;
			}
			return;
		}
		for(int i:a[x]){
			if(v[i]==0){
				p.push(i);
				v[i]=v[u]+1;
			}
		}
	}
	return;
}
void d(int s,int deep){
	if(deep==n+1){
		if(s!=k)return;
		int sum=0;
		mx=0;
		memset(v,0,sizeof(v));
		for(int i=1; i<=n; i++){
			if(vis[i]==1&&v[i]==0){
				sum++;
				dfs(i);
			}
		}
		if(sum>2)return;
		for(int i=1; i<=n; i++){
			if(vis[i]==1)continue;
			b(i);
		}
		if(mx<ans){
			ans=mx;
		}
		return;
	}
	vis[deep]=1;
	d(s+1,deep+1);
	vis[deep]=0;
	d(s,deep+1);
}
int main()
{
	//ios::sync_with_stdio(0);
	//cin.tie(0);cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>C;
	cin>>T;
	while(T--){
		ans=1e9;
		for(int i=1; i<=50; i++){
			a[i].clear();
		}
		cin>>n>>k;
		for(int i=1; i<=n-1; i++){
			int x,y;
			cin>>x>>y;
			a[x].push_back(y);
			a[y].push_back(x);
		}
		d(0,1);
		cout<<ans<<endl;
	}
	return 0;
}