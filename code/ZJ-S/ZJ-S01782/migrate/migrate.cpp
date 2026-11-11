#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+5,M=5e3+5,K=305,INF=1e18;
struct node{int val,minl;}cntw[K][K];
int c,T,n,d,s[N],ans=0,minn=INF;
int xs[N];
int solve(int sta,int end,int cnt)
{
	for(int i=2;i<=cnt;++i) {if(s[xs[i]]-s[xs[i-1]]>d) return 0;}
	if(s[xs[0]]-s[sta]>d) return 0;
	if((s[end]-s[xs[cnt]])>d) return 0;
	return 1;
}
void dfs(int sta,int end,int x,int k,int cnt)
{
	if(cnt>minn) return;
	if(x>k)
	{
		int w=solve(sta,end,cnt);
//		cout<<w<<" "<<cnt<<" "<<minn<<"\n";
		if(cnt==minn) ans+=w;
		else ans=w,minn=cnt;
		return;
	}
	dfs(sta,end,x+1,k,cnt);
	xs[cnt+1]=sta+x;
	dfs(sta,end,x+1,k,cnt+1);
	xs[cnt+1]=0;
}
void work2()
{
	ans=0;
	for(int i=1;i<=n;++i) for(int j=i+2;j<=n;++j) 
		{minn=INF;dfs(i,j,1,j-i-1,0);}
}
void work1()
{
	ans=0;
	for(int i=0;i<K;++i) for(int j=0;j<K;++j) cntw[i][j]={0,INF};
	for(int i=0;i<K;++i) cntw[i][i]={1,INF};
	for(int len=1;len<=n;++len)
		for(int i=1;i+len<=n;++i)
		{
			int j=i+len;
			for(int k=i;k<=j;++k)
			{
				node xxi=cntw[i][k],yyi=cntw[k][j];
				int l=xxi.minl+yyi.minl;
				if(l==cntw[i][j].minl) cntw[i][j].val+=xxi.val*yyi.val;
				else if(l<cntw[i][j].minl) cntw[i][j].val=xxi.val*yyi.val;
				cntw[i][j].minl=min(cntw[i][j].minl,l);
			}
			if(s[j]-s[i]<=d) cntw[i][j]={1,1};
		}	
	for(int i=1;i<=n;++i) for(int j=1;j<=n;++j) if(cntw[i][j].val==2) ans++;
}
signed main(void)
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
	cin>>c>>T;
	while(T--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;++i) cin>>s[i];
		if(n<=9) work2();
		else if(n<=300) work1();
		cout<<ans<<"\n";
	}
}
