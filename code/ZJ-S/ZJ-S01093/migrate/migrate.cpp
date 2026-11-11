#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2000005;
int c,t,n;
int L[N],R[N];
ll d,x[N];
void read(int &s)
{
	s=0;char c=getchar();int f=1;
	for(;c<48||c>57;c=getchar()) (c=='-')&&(f=-1);
	for(;c>47&&c<58;c=getchar()) s=(s<<1)+(s<<3)+(c^48);
	s*=f;
}
void read(ll &s)
{
	s=0;char c=getchar();int f=1;
	for(;c<48||c>57;c=getchar()) (c=='-')&&(f=-1);
	for(;c>47&&c<58;c=getchar()) s=(s<<1)+(s<<3)+(c^48);
	s*=f;
}
const int N2=5005;
bool h[N2][N2];
int s[N2];
bool check(int u,int v)
{
//	cout<<u<<' '<<v<<':'<<'\n';
	int k=0;
	while(u<v)
	{
		s[++k]=u;
		if(u==R[u]) return 0;
//		cout<<u<<' ';
		u=R[u];
	}
	s[++k]=v;
//	cout<<v<<'\n';
	bool fl=0;
	for(int i=3;i<=k;i++)
	{
		if(R[s[i-2]]-L[s[i]]>1) return 0;
		if(R[s[i-2]]-L[s[i]]==1)
		{
			if(!fl) fl=1;
			else return 0;
		}
	}
	return fl;
}
void solve1()
{
	for(;t;t--)
	{
		read(n);read(d);
		for(int i=1;i<=n;i++) read(x[i]);
		L[1]=1;
		for(int i=2;i<=n;i++)
		{
			L[i]=L[i-1];
			while(x[i]-x[L[i]]>d) L[i]++;
		}
		R[n]=n;
		for(int i=n-1;i;i--)
		{
			R[i]=R[i+1];
			while(x[R[i]]-x[i]>d) R[i]--;
		}
		int ans=0;
//		for(int i=1;i<=n;i++) cout<<L[i]<<' '<<R[i]<<'\n';
		for(int i=1;i<=n;i++) for(int j=i+2;j<=n;j++) if(check(i,j)) ans++;
		cout<<ans<<'\n';
	}
}
void solve2()
{
	for(;t;t--)
	{
		read(n);read(d);
		for(int i=1;i<=n;i++) read(x[i]);
		L[1]=1;
		for(int i=2;i<=n;i++)
		{
			L[i]=L[i-1];
			while(x[i]-x[L[i]]>d) L[i]++;
		}
		R[n]=n;
		for(int i=n-1;i;i--)
		{
			R[i]=R[i+1];
			while(x[R[i]]-x[i]>d) R[i]--;
		}
		int ans=0;
//		for(int i=1;i<=n;i++) cout<<L[i]<<' '<<R[i]<<'\n';
		for(int i=1;i<=n;i++)
		{
			int u=i,k=0;
			bool f1=0;
			while(u<=n)
			{
				s[++k]=u;
				if(u==R[u])
				{
					if(u!=n) f1=1;
					break;
				}
				u=R[u];
			}
//			cout<<i<<'\n';
			if(f1||k<3) continue;
			bool ff=0;
			int cnt=0,r=3;
			while(r<=k)
			{
				if(R[s[r-2]]-L[s[r]]==1){cnt=1;break;}
				else if(R[s[r-2]]-L[s[r]]>1){ff=1;break;}
				r++;
			}
			cout<<i<<' '<<s[r]<<' '<<t<<'\n';
			if(ff==1||!cnt) continue;
			int t=r;r++;
			while(r<=k&&cnt==1)
			{
				if(R[s[r-2]]-L[s[r]]==1) cnt=2;
				else if(R[s[r-2]]-L[s[r]]>1){ff=1;break;}
				r++;
			}
			if(ff==1) continue;
			ans+=r-t;
		}
		cout<<ans<<'\n';
	}
}
void solve3()
{
	for(;t;t--)
	{
		read(n);read(d);
		for(int i=1;i<=n;i++) read(x[i]);
		L[1]=1;
		for(int i=2;i<=n;i++)
		{
			L[i]=L[i-1];
			while(x[i]-x[L[i]]>d) L[i]++;
		}
		R[n]=n;
		for(int i=n-1;i;i--)
		{
			R[i]=R[i+1];
			while(x[R[i]]-x[i]>d) R[i]--;
		}
//		for(int i=1;i<=n;i++) cout<<L[i]<<' '<<R[i]<<'\n';
		int tt=R[1]-1,ans=0;
//		cout<<tt<<'\n';
		if(tt>1) ans=n-tt-1;
		cout<<ans<<'\n';
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	read(c);read(t);
	if(c<=10) solve1();
	else if(c<=12) solve3();
	else solve2();
	return 0;
}