#include <bits/stdc++.h>
using namespace std;
long long t[2000005],lazy[2000005],a[500005];
void up(int i)
{
	t[i]=t[2*i]+t[2*i+1];
}
void push_down(int i,int x,int y)
{
	if(!lazy[i])return;
	int mid=(x+y)/2;
	t[2*i]+=(mid-x+1)*lazy[i];
	t[2*i+1]+=(y-mid)*lazy[i];
	lazy[2*i]+=lazy[i];
	lazy[2*i+1]+=lazy[i];
	lazy[i]=0;
}
void add(int x,int y,int i,int l,int r,long long k)
{
	if(l<=x&&y<=r)
	{
		t[i]+=(y-x+1)*1ll*k;
		lazy[i]+=k;
		return;
	}
	push_down(i,x,y);
	int mid=(x+y)/2;
	if(mid>=l)add(x,mid,2*i,l,r,k);
	if(mid<r)add(mid+1,y,2*i+1,l,r,k);
	up(i);
}
long long quary(int x,int y,int i,int l,int r)
{
	if(l<=x&&y<=r)return t[i];
	push_down(i,x,y);
	int mid=(x+y)/2;
	long long res=0;
	if(mid>=l)res+=quary(x,mid,2*i,l,r);
	if(mid<r)res+=quary(mid+1,y,2*i+1,l,r);
	return res;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n;
	long long m,ans=1;
	cin >> n >> m;
	for(int i = 1;i<=n;i++)
		cin >> a[i];
	sort(a+1,a+n+1);
	for(int i = 2;i<=n;i++)
	{
		long long cha=a[i]-a[i-1];
		add(1,n,1,1,i-1,cha);
		long long sum=quary(1,n,1,1,i);
		if(sum<=m)ans=max(ans,i*1ll);
		else
		{
			int l=1,r=i-1,anss=0;
			while(l<=r)
			{
				int mid=(l+r)/2;
				if(quary(1,n,1,1,mid)>=sum-m)
				{
					r=mid-1;
					anss=mid;
				}
				else
				{
					l=mid+1;
				}
			}
			ans=max(ans,(i-anss)*1ll);
		}
	}
	cout << ans;
	return 0;
 }
