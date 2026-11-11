#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e3+5,M=2e6+5;
int a[M];
struct tree
{
	int l,r;
	int minn,s;
}tr[N<<2];
void pushup(int x)
{
	tr[x].minn=min(tr[x<<1].minn,tr[x<<1|1].minn);
	int sum=0;
	if(tr[x<<1].minn==tr[x].minn)sum+=tr[x<<1].s;
	if(tr[x<<1|1].minn==tr[x].minn)sum+=tr[x<<1|1].s;
	tr[x].s=sum;
}
void build(int x,int l,int r)
{
	tr[x]={l,r,2000000000000000000ll,0ll};
	if(l==r)return;
	int mid=l+r>>1;
	build(x<<1,l,mid);
	build(x<<1|1,mid+1,r);
}
void add(int x,int l,int r,int p,int k,int s)
{
	if(l==r)
	{
		tr[x].minn=k;
		tr[x].s=s;
		return;
	}
	int mid=l+r>>1;
	if(p<=mid)add(x<<1,l,mid,p,k,s);
	else add(x<<1|1,mid+1,r,p,k,s);
	pushup(x);
}
pair<int,int> query(int x,int l,int r,int ql,int qr)
{
	if(ql<=l&&r<=qr)return {tr[x].minn,tr[x].s};
	int mid=l+r>>1;
	int minn=2e18,s=0;
	if(ql<=mid)
	{
		pair<int,int>tmp=query(x<<1,l,mid,ql,qr);
		if(minn>tmp.first)minn=tmp.first,s=tmp.second;
		else if(minn==tmp.first)s+=tmp.second;
	}
	if(qr>mid)
	{
		pair<int,int>tmp=query(x<<1|1,mid+1,r,ql,qr);
		if(minn>tmp.first)minn=tmp.first,s=tmp.second;
		else if(minn==tmp.first)s+=tmp.second;
	}
	if(s>3)s=min(s,3ll);
	return {minn,s};
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;
	cin>>c>>T;
	while(T--)
	{
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		if(c>=11&&c<=12)
		{
			int tmp=d/(a[2]-a[1]);
			if(tmp<=1)cout<<0<<'\n';
			else cout<<max(0ll,n-2*tmp+1)<<'\n';
			continue;
		}
		else
		{
			int ans=0;
			for(int i=1;i<=n;i++)
			{
				build(1,1,n);
				add(1,1,n,i,0,1);
				for(int j=i+1;j<=n;j++)
				{
					int l=i,r=j-1,tmp=j;
					while(l<=r)
					{
						int mid=l+r>>1;
						if(a[j]-a[mid]<=d)r=mid-1,tmp=mid;
						else l=mid+1;
					}
					if(tmp==j)break;
					pair<int,int>qwq=query(1,1,n,tmp,j-1);
					int minn=qwq.first,s=qwq.second;
					if(s==2)ans++;
					add(1,1,n,j,minn+1,s);
				}
			}
			cout<<ans<<'\n';
		}
	}
	return 0;
}
