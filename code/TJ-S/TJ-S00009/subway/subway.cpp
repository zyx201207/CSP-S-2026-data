#include<bits/stdc++.h>
using namespace std;
#define f(i,a,b)for(int i = a;i<=b;i++)
#define f_(i,a,b)for(int i = a;i>=b;i--)
const int N = 510;
const int M = 5e5+10;
long long n,m,c,d,q;
bool vis[M];
long long dp[M],tu[500][2000],w[M];
int final[M];
int ke = 0;
struct Node{
	int from,to,len,num,pre;
}a[N];
void dij(int s,int e){
	memset(dp,0x3f,sizeof(dp));
	memset(vis,false,sizeof(vis));
	dp[s] = 0;
	vis[s] = true;
	
	f(i,1,m){	
		int z = -1;
		f(j,1,m){
			if(z == -1||(vis[j] == false&&dp[z]<dp[j]))
			z = j;
		}
		cout<<z<<endl;
		vis[z] = true;
		long long change = 0;
		for(int j = final[z];j!=-1;j = a[j].pre){
			int d = a[j].to;
			if(a[j].num!=a[z].num){
				change = tu[a[z].num][d];
			}else{
				change = 0;
			}
			if(dp[j]>dp[z]+a[d].len+change){
				dp[j] = dp[z]+a[d].len+change;
			}
		}
	}
}
void add(int u,int v,int w,int bj){
	ke++;
	a[ke].from = u;
	a[ke].to = v;
	a[ke].len = w;
	a[ke].num = bj;
	a[ke].pre = final[u];
	final[u] = ke;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	memset(final,-1,sizeof(final));
	int bj = 0;
	f(i,1,m)cin>>w[i];
	f(i,1,n){
		int k;
		cin>>k;
		++bj;
		long long t;
		int s;
		cin>>s>>t;
		tu[i][s] = t;
		f(j,2,k){
			int u;
			cin>>u>>t;
			tu[i][j] = t;
			add(s,u,t,bj);
			add(u,s,t,bj);
		}
	}
	f(i,1,q){
		int st,en;
		cin>>st>>en;
		dij(st,en);
		cout<<dp[en]+w[st]+w[en]+tu[st][st]<<endl;
	}
	return 0;
} 
