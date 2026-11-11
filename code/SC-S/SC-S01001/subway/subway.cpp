#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=5e5+10;
ll c,n,m,d,q,ans;
ll w[N],l,e,s;
ll a[510][510][3],k[1000010];
bool vis[N];
bool check(int line,int x){
	for(int i=1;i<=n;i++){
		if(i==line) continue;
		for(int j=1;j<=k[i];j++){
			if(a[i][j][1]==x){
				c=i;
				return true;
			} 
		}
	}
	return false;
}
void dfs(int x,ll sum,int line){
	if(sum>ans){
		return;
	}
	if(x==e){
		ans=min(ans,sum);
	}
	for(int i=1;i<=n;i++){
		if(line==i) continue;
		bool p=check(x,line);
		for(int j=1;j<=k[i]&&p;j++){
			dfs(j,sum+a[i][j][2],i);
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			ll x,y;
			cin>>x>>y;
			a[i][j][1]=x;
			a[i][j][2]=y;
		}
	}
	while(q--){
		memset(vis,0,sizeof(vis));
		ans=0x3f3f3f3f;
		cin>>s>>e;
		if(check(s,0)){
			dfs(s,0,l);
		}
		cout<<ans+w[s]+w[e]<<endl;
	}
	
	return 0;
}