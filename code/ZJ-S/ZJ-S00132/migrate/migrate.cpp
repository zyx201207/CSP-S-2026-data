#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
ll c,T,n,d;
ll x[N];
//ll f[305][305][305];
struct node{
	int to,x;
	bool operator<(const node &b)const{
		return b.x<x;
	}
};
int dis[N],dp[N];
int ans;
void bfs(int st){
	priority_queue<node> q;
	q.push((node){st,0});
	memset(dp,0,sizeof(dp));
	memset(dis,0x3f,sizeof(dis));
	while(!q.empty()){
		node now=q.top();q.pop();
		if(dis[now.to]==now.x)dp[now.to]++;
		else if(dis[now.to]>now.x)dis[now.to]=now.x,dp[now.to]=1;
		else continue;
		for(int i=now.to+1;i<=n;i++){
			if(x[i]-x[now.to]>d)break;
			q.push((node){i,now.x+1});
		}
	}
	for(int i=st+1;i<=n;i++){
		if(dp[i]==2)ans++;
	}
	return ;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
//	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		ans=0;
		if(c>=0&&c<=10){
			for(int i=1;i<=n;i++){
				bfs(i);
			}
			cout<<ans<<"\n";
		}else cout<<0<<"\n";
	}
	return 0;
}