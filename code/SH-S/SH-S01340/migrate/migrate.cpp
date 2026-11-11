#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
const int N=5005,M=2000005;
int cid,_,n,d,ans,a[M],p[N],l1[N],l2[N],L[N],R[N],f[N],s[N],len[N],pd[N];
void solve()
{
	ans=0;
	cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>p[i],l1[i]=i,pd[i]=0;
	for(int i=1;i<=n;i++)
	{
		if(i>=3&&p[i]<=p[i-2]+d) pd[i]=1;
	}
	int j=1;
	for(int i=1;i<=n;i++)
	{
		while(j<i&&p[i]-p[j]>d) j++;
		l1[i]=j;
	}
	for(int i=1;i<=n;i++)
	{
		len[i]=0;
		f[i]=1,s[i]=1,s[i-1]=0;
		for(int j=0;j<i;j++) s[j]=0;
		int mx=0;
		for(int j=i+1;j<=n;j++)
		{
			f[j]=0;
			if(p[j]-p[j-1]>d) break;
			if(l1[j]<i) len[j]=1;
			else len[j]=len[l1[j]]+1;
			mx=max(mx,len[j]);
		}
		for(int i=1;i<=mx;i++) L[i]=1e9,R[i]=0;
		for(int j=i+1;j<=n;j++)
		{
			if(p[j]-p[j-1]>d) break;
			L[len[j]]=min(L[len[j]],j);
			R[len[j]]=max(R[len[j]],j);
		}
		L[0]=i,R[0]=i;
		for(int j=i+1;j<=n;j++)
		{
			if(p[j]-p[j-1]>d) break;
			int nl=max(L[len[j]-1],l1[j]),nr=R[len[j]-1];
			if(nl<=nr) f[j]=min(3ll,s[nr]-s[nl-1]);
			if(f[j]==2) ans++;
			s[j]=s[j-1]+f[j];
		}
	}
	cout<<ans<<'\n';
	return;
}
void solveA()
{
	ans=0;
	cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n==1)
	{
		cout<<0<<'\n';
		return;
	}
	if(d<2*(a[2]-a[1]))
	{
		cout<<0<<'\n';
		return;
	}
	int len=2*(d/(a[2]-a[1]));
	if(len<=n) cout<<n-len+1<<'\n';
	else cout<<0<<'\n';
	return;
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>cid>>_;
	if(cid<=10)
	{
		while(_--) solve();
		return 0;
	}
	if(cid>=11&&cid<=12)
	{
		while(_--) solveA();
		return 0;
	}
	return 0;
}
