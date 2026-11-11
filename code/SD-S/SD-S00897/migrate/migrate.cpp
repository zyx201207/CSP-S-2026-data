#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define int long long
#define pii pair<int,int>
#define fi first
#define se second
#define pb emplace_back

const int mod=998244353;

const int N=5010,M=2000010;

int c,t,n,d,x[M],ans,di[N][N]; 

int nx[M],num[M],f[M],g[M],k0[M],k1[M];

// 跳到下一个位置，那个已经处理好了有多少个o合法了的和呵呵的
//这个是错的 
 
void get(int u){
	int u1=u;di[u][u]=0;
	int o=0;
	while(u!=n){
		int nxt=upper_bound(x+1,x+1+n,x[u]+d)-x-1;
		if(nxt==u){for(int i=u+1;i<=n;i++)di[u1][i]=1e9;return ;}
		o++;
		for(int i=u+1;i<=nxt;i++)di[u1][i]=o;
		u=nxt;
	}
}

void check(int u,int v){
	int u1=u;if(di[u][v]==1e9)return ;
	if(di[u][v]<=1)return ;
	int o=0;
	while(u!=v){
		int nxt=upper_bound(x+1,x+1+n,x[u]+d)-x-1;
		if(nxt>v)nxt=v;
		if(nxt-u>1){
			if(di[u1][v]==di[u1][nxt-1]+di[nxt-1][v])o++;
			if(nxt-u>2&&di[u1][v]==di[u1][nxt-2]+di[nxt-2][v])return ;
		}
		if(o>=2)return ;
		u=nxt;
	}
	if(o==1){
		ans++;
//		cout<<u1<<" "<<v;
	}
}

void gt(int o,int u){
		int nxt=upper_bound(x+1,x+1+n,x[u]+d)-x-1;
//		if(nxt>v)nxt=v;
		//第一步肯定是跳满的且不统计，从第二步开始计数，所以u起点固定了
		//在这个点，第一步跳满的答案已经被计算了 
		int l=lower_bound(x+1,x+1+n,x[nxt]-d)-x;
		if(u-l+1>2){k0[o]=k1[o]=0;return ;}
		int op=0;
//		if(o<u-1&&nxt-u>1){
//			int o1=u-1,o2=nxt-1;
//			if(x[o2]-x[o1]<=d&&x[nxt]-x[o1]<=d)op=1;
//		}
		if(op&&u-l+1==2){k0[o]=k1[o]=0;return ;}
		if(u-l+1==2||op){
			k0[o]=0;k1[o]=k0[u];
			num[o]=k1[o];
//			if(o==1)cout<<111;
		}
		else{
			k0[o]=k0[u];k1[o]=k1[u];
			num[o]=k1[o];
//			if(o==1)cout<<222;
		}
//		u=nxt;
//	}
}

void solve2(){
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	ans=0;int l1=0,l2=0;
	for(int i=1;i<=n;i++){
		int nxt=upper_bound(x+1,x+1+n,x[i]+d)-x-1;
		nx[i]=nxt;
		if(i-1>=1){
			l1=upper_bound(x+1,x+1+n,x[i-1]+d)-x-1;
			l1=max(i,l1);
			f[i]=nxt-l1;
			if(i-1>=2){
				l2=upper_bound(x+1,x+1+n,x[i-2]+d)-x-1;
				l2=max(i,l2);
				g[i]=l1-l2;
			}
//			cout<<nx
		}
//		else f[i]=1;
		//f 这个唯一的，g可以贡献一个o的 
//		cout<<nx[i]<<"："<<f[i]<<" "<<g[i]<<endl;
	}
	//记录原来的合法的答案喵
	x[0]=-3e18; 
	for(int i=n;i>=1;i--){
		if(x[nx[i]]==x[i]){//跳不动了 
			k0[i]=k1[i]=0;
		}
		else{
			gt(i,nx[i]);
			k0[i]+=f[nx[i]];
			k1[i]+=g[nx[i]];
//			cout<<i<<":"<<nx[i]<<" "<<g[nx[i]]<<" "<<k1[i]<<endl;
			num[i]=k1[i];
			ans+=num[i];
		}
	}
	cout<<ans<<"\n";
}

void solve(){
	cin>>n>>d;
//	memset(di,0,sizeof di);
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	ans=0;
	for(int i=1;i<=n;i++)
		get(i);
//	for(int i=1;i<=n;i++){
//	for(int j=1;j<=n;j++)
//	cout<<di[i][j]<<" ";
//	cout<<endl;
//	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			check(j,i);
		}
	}
	cout<<ans<<"\n";
}

void solve1(){
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	if(n==1){
		cout<<0<<"\n";
		return ; 
	}
	int cha=x[2]-x[1];
	int bei=d/cha;
	if(bei<=1){
		cout<<0<<"\n";
		return ; 
	}
	else{
		int kk=bei*2;
		int opp=max(0ll,n-kk+1);
		cout<<opp<<"\n";
		return ;
	}
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c<=10){
		while(t--){
			solve();
		}
		return 0;
	}
	if(c>=11&&c<=12){
		while(t--){
			solve1();
		}	
	}
	else {
		while(t--){
			solve2();
		}
	} 
	return 0;
}
