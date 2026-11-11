#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int c,n,m,d,q,w[N],k[501],vis[N],x,y,ans;

struct stu{
	int x,y;
};stu ss[N];
vector<stu>a[501];
vector<stu>b[N];
queue<stu>qq;
void dfs(int dx,int s){
	//ss[cnt].x=dx,ss[cnt].y=s;
	if(dx==y){
		ans=min(ans,s);
		//for(int i=1;i<=cnt;i++)cout<<ss[i].x<<" "<<ss[i].y<<endl;
		//cout<<ans<<endl;
		return;	
	}
	for(auto i:b[dx]){
		for(auto j:a[i.x]){
			if(vis[j.x]!=1){
				vis[j.x]=1;
				dfs(j.x,s+i.y+j.y);
				vis[j.x]=0;
			}
		}
	} 
	return;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		int u,v;
		for(int j=1;j<=k[i];j++){
			cin>>u>>v;
			a[i].push_back({u,v});
			b[u].push_back({i,v});
		}
	}
	//if(c<=11){
		while(q--){
			ans=1145141919810;
			for(int i=1;i<=m;i++)vis[i]=0;
			cin>>x>>y;
			vis[x]=1;
			dfs(x,w[x]);
			cout<<ans+w[y]<<endl;
		}
	//}
	return 0;
}
