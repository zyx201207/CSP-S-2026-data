#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll c,n,m,d,q;
ll w[100005],t[100005];
ll a[10005][10005];
ll b[100005];
ll start,end2;
ll ans,sum;
bool vis[100005];
void BFS(ll root){
	if(root==end2){
		ans=min(sum,ans);
		return;
	}
	for(ll i=1;i<=n;i++){ 	
		if(a[root][i]==1){
			if(b[root]==b[i]&&vis[i]!=1){
				vis[i]=1;
				BFS(i);
				vis[i]=0;
			}
			else if(b[root]!=b[i]&&vis[i]!=1){
				sum=sum+t[i]+w[i];
				vis[i]=1;
				BFS(i);
				vis[i]=0;
			}
		}
	}
	ans=min(sum,ans);
	return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k,x,y;
		cin>>k;
		cin>>x>>t[x];
		b[x]=i;
		for(int j=2;j<=k;j++){
			cin>>y>>t[y];
			b[y]=i;
			a[x][y]=1;
			a[y][x]=1;
			x=y;
		}
	}
	while(q--){
		cin>>start>>end2;
		sum=0,ans=100005;
		BFS(start);
		cout<<ans+w[start]+w[end2]<<"\n";
	}
	return 0;
}