#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N=2e6+9;
const ll INF=1e18+9;
struct Node{
	int x,y;
};

ll A[N];int p[10];
int vis[N],use[N],sum[N],q[N],ql,qr;
int c,T,n;ll d,ans;

/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

1
2
*/
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

0
1
*/
/*
0 1
10 3
0 3 6 7 8 9 10 11 14 17

9
*/

inline ll  read();

inline void dfs(int w);

inline int  upper(ll l,ll r);
inline bool check(int u,int v);
inline void clean();

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	scanf ("%d %d",&c,&T);
	
	while (T-->0)
	{
		scanf ("%d %lld",&n,&d);
		ans=0;
		
		for (int i=1;i<=n;i++)
			A[i]=read();
		stable_sort(A+1,A+n+1);
		
		if (c!=11 and c!=12)
		{
			for (int i=1;i<=n;i++)
			{
				while (qr)
					q[qr--]=0;
				ql=1,qr=0;
				for (int j=1;j<=n;j++)
					vis[j]=sum[j]=0;
				
				q[++qr]=i,sum[i]=1;
				dfs(1);
				
				for (int j=1;j<=n;j++)
					ans+=(vis[j] and sum[j]==2);
			}
		}
		else
		{
			int x,y,z,top,len;
			for (int i=1;i<=1;i++)
			{
				x=i,y=0,z=0,top=i+1;
				while (top<=n)
				{
					while (top<=n and check(x,top) and check(y,top))
					{
						if (!check(z,top))
							len=top-i+1,ans++;
						top++;
					}
					if (x)
						p[1]=upper(A[x]+1,A[x]+d),
						p[2]=upper(A[x]+1,A[p[1]]-1),
						p[6]=upper(A[x]+1,A[p[2]]-1);
					if (y)
						p[3]=upper(A[y]+1,A[y]+d),
						p[4]=upper(A[y]+1,A[p[3]]-1);
					if (z)
						p[5]=upper(A[z]+1,A[z]+d);
					clean();
					
					if (!p[1])
						break;
					
					top=p[1]+1,x=p[1],y=p[2],z=p[3];
					p[1]=p[2]=p[3]=p[4]=p[5]=p[6]=0;
				}
				if (ans==0)
				{
					ans=0;
					break;
				}
				else
				{
					ans=n-len+1;
					break;
				}
			}
		}
		
		printf ("%lld\n",ans);
	}
	
	return 0;
}

inline ll read()
{
	ll o=0,c=0,g=0;
	while (c<'0' or c>'9')
		g=(c=='-'),c=getchar();
	while (c>='0' and c<='9')
		o=(o<<1)+(o<<3)+(c^48),c=getchar();
	return (!g)?o:-o;
}

inline void dfs(int w)
{
	if (ql>qr)
		return ;
	
	int tip=qr;
	while (ql<=tip)
	{
		int x=q[ql++];
		for (int i=x+1;i<=n and A[i]<=A[x]+d;i++)
			if (vis[i] and vis[i]!=w)
				continue;
			else
			{
				vis[i]=w,sum[i]+=sum[x];
				if (!use[i])
					use[i]=1,q[++qr]=i;
			}
	}
	for (int i=1;i<=n;i++)
		use[i]=0;
	dfs(w+1);
}

inline int upper(ll l,ll r)
{
	int dl=1,dr=n,mid,res=0;
	while (dl<=dr)
	{
		mid=(dl+dr)>>1;
		if (A[mid]>r)
			dr=mid-1;
		else
			dl=mid+1;
		if (A[mid]<=r and A[mid]>=l)
			res=mid;
	}
	return res;
}

inline bool check(int u,int v)
{
	if (u and A[u]<=A[v] and A[v]<=A[u]+d)
		return true;
	return false;
}

inline void clean()
{
	if (p[2]<p[3])
		swap(p[2],p[3]);
	p[3]=max({p[3],p[4],p[5],p[6]});
}

