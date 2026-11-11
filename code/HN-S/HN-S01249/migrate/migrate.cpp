#include<bits/stdc++.h>
#define eps 1e-7
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int,int> pii;
#define fi first
#define se second
#define MAXN 2000005
int C,m,n;LL d,A[MAXN],a[MAXN],ans;
int p[MAXN],f[5005][5005],g[5005][5005],sg[5005][5005];
int rt[5005][5005],lt[5005][5005];
void Solve1(){
	for(int i=1;i<=n;i++)
		for(int j=max(i+1,p[i-1]);j<=n;j++)
			if(a[j]-a[i]>d)break;
			else p[i]=j;
	for(int j=1;j<=n;j++){
		f[j][j]=0,sg[j][j]=g[j][j]=1,rt[j][j]=lt[j][j]=j;
		for(int i=j-1;i>=1;i--){
			int pp=min(p[i],j);
			f[i][j]=f[pp][j]+1;
			int t=lt[rt[pp][j]][j];
			g[i][j]=sg[t][j]-sg[pp+1][j];
			if(g[i][j]>=3)g[i][j]=3;
			if(f[i][j]==f[i+1][j])rt[i][j]=rt[i+1][j],lt[rt[i][j]][j]--;
			else rt[i][j]=lt[i][j]=i;
			sg[i][j]=sg[i+1][j]+g[i][j];
			if(g[i][j]==2)ans++;
		}
		// cout<<j<<": ";
		// for(int i=1;i<=j;i++)
		// 	cout<<g[i][j]<<' ';
		// cout<<'\n';
	}
}
void solve(int l,int r){
	n=r-l+1,a[n+1]=0;
	for(int i=l;i<=r;i++)a[i-l+1]=A[i];
	if(m<=5000)Solve1();
}
void solve(){
	ans=0;
	cin>>m>>d;
	for(int i=1;i<=m;i++)cin>>A[i];
	if(m<=2)return cout<<0<<'\n',void();
	if(C==11||C==12){
		LL D=A[2]-A[1];
		if(D>=d)return cout<<0<<'\n',void();
		LL t=d/D*2;
		cout<<max(0ll,m-t+1)<<'\n';
		return;
	}
	if(0&&(C==13||C==14)){
		int O=0;
		for(int i=2;i<m;i++){
			if(A[i]-A[1]<=d&&A[m]-A[i]<=d){
				O=i;break;
			}
		}
		int rl=O,rl2=O,lr=O,lr2=O;
		while(A[O+1]-A[rl]<=d)rl--;
		if(O==m-1)rl2=O+1;
		else while(A[O+2]-A[rl2]<=d)rl2--;
		while(A[lr]-A[1]<=d)lr++;
		if(O==2)lr2=O+1;
		else while(A[lr2]-A[1]<=d)lr2++;
	}
	A[m+1]=A[m]+d+1;
	int las=1;
	for(int i=2;i<=m+1;i++)
		if(A[i]-A[i-1]>d)
			solve(las,i-1),las=i;
	cout<<ans<<'\n';
}
signed main(){
	auto ST=clock();
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int T=1;cin>>C>>T;
	while(T--)solve();
	auto EN=clock();
	cerr<<LD(EN-ST)/CLOCKS_PER_SEC<<endl;

	return 0;
}