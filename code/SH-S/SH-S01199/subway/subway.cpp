#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,n,m,d,q;
ll ans;
ll w[500005];
ll k[505];
vector <ll> a[500005],t[500005],met[500005];
bool vis[500005];
void dfs(int x,int y,ll stop,ll time){
	if(stop==y){
		ans=min(ans,time);
		return;
	}
	for(auto i:met[stop]){
		
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int i=1;i<=k[i];i++){
			ll q1,q2;
			cin>>q1,q2;
			a[k[i]].push_back(q1);
			t[k[i]].push_back(q2);
			met[q1].push_back(i);
		}
	}
	for(int i=1;i<=q;i++){
		ans=0x3f3f3f3f3f3f3f3f;
		memset(vis,0,sizeof vis);
		int x, y;
		cin>>x>>y;
		dfs(x,y,x,0);
	}                      
}
