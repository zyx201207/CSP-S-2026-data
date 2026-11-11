#include<bits/stdc++.h>
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define dep(i,a,b) for(int i=(a);i>=(b);i--)
#define endl '\n'
using namespace std;
const int maxn=5007;
int n,m,d,q;
ll dp[maxn][maxn],w[maxn][maxn],cnt;
int sta[maxn],sub[maxn][maxn];//第i个的站台到第j号线的节点编号 

void add(int i,int cnt,ll tmp){
	w[i][cnt]=w[cnt][i]=tmp;
	dp[i][cnt]=dp[cnt][i]=tmp;
}
void flody(){
	rep(u,1,n){
		rep(m,u,n){
			rep(v,m,n){
			
				dp[u][v]=min(dp[u][v],dp[u][m]+dp[m][v]);
				dp[v][u]=min(dp[v][u],dp[v][m]+dp[m][u]);
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>n>>n>>m>>d>>q;
	memset(w,-0x3f,sizeof(w));
	memset(dp,0x3f,sizeof(dp));
	cnt=n;
	rep(i,1,n)dp[i][i]=0;
	rep(i,1,m)
	{
		cnt++;
		int tmp;cin>>tmp;
		add(i,cnt,tmp);
		sta[i]=cnt;
	}
	rep(i,1,n){
		int k;cin>>k;
		int last=0;
		rep(i,1,k){
			int a,b;cin>>a>>b;
			cnt++;
			sub[sta[a]][i]=cnt;
			add(sta[a],cnt,b) ;
			if(last!=0)add(last,cnt,0);
			last=cnt;
		}
	}
	flody();
	while(q--){
		int u,v;cin>>u>>v;
		cout<<min(dp[u][v],dp[v][u])<<endl;
		
	}
}
