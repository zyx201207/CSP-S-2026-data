#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,x,y;
long long w[500005],ans;//s站几分钟 
bool vis[500005];
struct l{
	int s,t;
}a[505][500005];//i号线xx站  是第j站 要t分钟 
priority_queue<int>qu;
int dfs(int x,long long ans){
	vis[x]=true;
	if(x==y) qu.push(ans);
	for(int i=1;i<=505;i++){
		if(a[i][x].s!=0){
			for(int j=1;j<=505;j++){
				if(a[i][j].s!=0&&!vis[j]){
					ans+=a[i][j].t*2;
					return dfs(j,ans);
				}
			}
		}
	} 
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1;j<=k;j++){
			int xx;cin>>xx;
			a[i][xx].s=j;
			cin>>a[i][j].t;
		}
	}
	while(q--){
		ans=0;
		cin>>x>>y;
		ans+=w[x]+w[y];
		int tmp = dfs(x,ans);
		cout<<qu.top()<<endl;
	}
}
