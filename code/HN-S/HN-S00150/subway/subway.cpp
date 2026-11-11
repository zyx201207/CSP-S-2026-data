#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
int read(){int x=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}return x*f;}
typedef long long ll;
const int N=510,M=2e4+10;
int w[M];
struct edge{int v,val;};
vector<edge>mp[M+N];
void dij(int s,int t){
	ll sum=0;
	queue<int>q;
	q.push(s);
	while(!q.empty()){
		int u=q.front();q.pop();
		for(int i=0;i<(int)mp[u].size();i++){
			int v=mp[u][i].v,val=mp[u][i].val;
			q.push(v);
		}
	}
}
ll dp[15010][15010];
int main(){
	freopen("subway.in","r",stdin);
//	freopen("ans.txt","w",stdout);
	freopen("subway.out","w",stdout);
	int c=read(),n=read(),m=read(),d=read(),q=read();
	rep(i,1,m) w[i]=read();//m个点 
	memset(dp,63,sizeof(dp));
	rep(i,1,n+m) dp[i][i]=0;
	rep(i,1,n){//n个新点
		int k=read();
		rep(j,1,k){
			int v=read(),t=read(),u=m+i;
			mp[v].push_back({u,t});
			mp[u].push_back({v,t});
			dp[u][v]=t;dp[v][u]=t;
		}
	}
	rep(k,1,n+m) rep(i,1,n+m) rep(j,1,m+n) if(i!=j&&j!=k&&k!=i) dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);	
//	rep(i,1,n+m) rep(j,1,n+m) cout<<dp[i][j]<<" \n"[j==n+m];
	rep(i,1,q){
		int s=read(),t=read();
//		dij(s,t);
		cout<<dp[s][t]+(ll)(w[s]+w[t])<<"\n";
	}
	return 0;
} 
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/

