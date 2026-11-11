#include<bits/stdc++.h>
using namespace std;
const long long INF=1e18;
int cid,t;
long long n,D,a[2000005],lf[2000005],rf[2000005],gs[2000005],f[2000005],g[2000005];
bool ls[2000005],rs[2000005];
int pl[2000005],sr[2000005],to[2000005];
void solvebf()
{
	multiset<long long>S;
	cin>>n>>D;
	for(int i=1;i<=n;i++) cin>>a[i];
	long long ans=0;
	for(int st=1;st<=n;st++)
	{
		S.clear();
		for(int i=st;i<=n;i++) f[i]=INF,g[i]=0;
		for(int i=0;i<=n+2;i++) gs[i]=0;
		f[st]=0,g[st]=1,S.insert(0),gs[0]=1;
		for(int i=st+1,j=st;i<=n;i++)
		{
			while(j<=i&&a[i]-a[j]>D)
			{
				if(f[j]!=INF) S.erase(S.find(f[j])),gs[f[j]]-=g[j];
				j++;
			}
			if(!S.empty())
			{
				long long mn=(*S.begin());
				f[i]=mn+1,g[i]=gs[mn];
				if(mn!=INF) S.insert(f[i]),gs[f[i]]+=g[i];
			}
		}
		for(int i=st;i<=n;i++) if(g[i]==2) ans++;
	}
	cout<<ans<<"\n";
}
void solve()
{
	cin>>n>>D;
	for(int i=0;i<=n+2;i++) ls[i]=rs[i]=0;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1,j=1;i<=n;i++)
	{
		while(j<=i&&a[i]-a[j]>D) j++;
		lf[i]=j;
	}
	for(int i=n,j=n;i>=1;i--)
	{
		while(j>=i&&a[j]-a[i]>D) j--;
		rf[i]=j;
	}
	for(int i=1;i+3<=n;i++)
	{
		if(a[i+3]-a[i]>D&&a[i+3]-a[i+1]<=D&&a[i+2]-a[i]<=D) ls[i]=1,rs[i+3]=1;
	}
//	for(int i=1;i<=n;i++) cerr<<ls[i];
//	cerr<<"\n";
//	for(int i=1;i<=n;i++) cerr<<rs[i];
//	cerr<<"\n";
	int lst=0,z=1;
	for(int i=1;i<=n;i++)
	{
		if(i!=1&&a[i]-a[i-1]>D) z=i;
		pl[i]=max(lst,z-1),lst=(ls[i]?i:lst);
	}
	lst=n+1,z=n;
	for(int i=n;i>=1;i--)
	{
		if(i!=n&&a[i+1]-a[i]>D) z=i;
		sr[i]=min(lst,z+1),lst=(rs[i]?i:lst);
	}
//	for(int i=1;i<=n;i++) cerr<<pl[i];
//	cerr<<"\n";
//	for(int i=1;i<=n;i++) cerr<<sr[i];
//	cerr<<"\n";
	long long ans=0;
	for(int i=1;i<=n;i++)
	{
		if(ls[i]) ans=(ans+1ll*(i-pl[i])*(sr[i+3]-i-3));
	}
	cout<<ans<<"\n";
}
void solve1()
{
	cin>>n>>D;
	for(int i=0;i<=n+2;i++) ls[i]=rs[i]=0;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1,j=1;i<=n;i++)
	{
		while(j<=i&&a[i]-a[j]>D) j++;
		lf[i]=j;
	}
	for(int i=n,j=n;i>=1;i--)
	{
		while(j>=i&&a[j]-a[i]>D) j--;
		rf[i]=j;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(a[j]-a[i]>D)
			{
				int u=lf[j],v=rf[i];
				if(u<v)
				{
					ls[i]=1,rs[j]=1,to[i]=j;
					break;
				}
			}
		}
	}
//	for(int i=1;i<=n;i++) cerr<<ls[i];
//	cerr<<"\n";
//	for(int i=1;i<=n;i++) cerr<<rs[i];
//	cerr<<"\n";
	int lst=0,z=1;
	for(int i=1;i<=n;i++)
	{
		if(i!=1&&a[i]-a[i-1]>D) z=i;
		pl[i]=max(lst,z-1),lst=(ls[i]?i:lst);
	}
	lst=n+1,z=n;
	for(int i=n;i>=1;i--)
	{
		if(i!=n&&a[i+1]-a[i]>D) z=i;
		sr[i]=min(lst,z+1),lst=(rs[i]?i:lst);
	}
	long long ans=0;
	for(int i=1;i<=n;i++)
	{
		if(ls[i]) ans=(ans+1ll*(i-pl[i])*(sr[to[i]]-to[i]));
	}
	cout<<ans<<"\n";
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>cid>>t;
	if(cid<=10)
	{
		while(t--) solvebf();
		return 0;
	}
	else
	{
		while(t--) solve1();
		return 0;
	}
	return 0;
}
/*
Given n,D.
D=2
1 2 3 4 5 6 7

f[i],g[i]

0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 1
5 2
1 2 3 4 5

0 1
5 3
1 3 4 6 9

0 1
9 3
1 4 6 7 9 12 14 15 17 19

0 6
5 1
4 6 7 9 10
5 2
4 6 7 9 10
5 3
4 6 7 9 10
5 4
4 6 7 9 10
5 5
4 6 7 9 10
5 6
4 6 7 9 10

4 6 7 9

0 1
6 2
-4 -3 -2 -1 3 6

(u,v)
*/
