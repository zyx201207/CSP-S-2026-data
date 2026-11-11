#include<bits/stdc++.h>
using namespace std;
#define int long long
char input[1<<20],*pf,*pe;
#define gc() (pf==pe&&(pe=(pf=input)+fread(input,1,1<<20,stdin),pf==pe)?EOF:*pf++)
int rdi()
{
	int n=0,k=1,c=gc();
	for(;!isdigit(c);c=gc())
	{
		if(c=='-')
		{
			k=-1;
		}
	}
	for(;isdigit(c);c=gc())
	{
		n=n*10+c-48;
	}
	return n*k;
}
const int N=5e5+35;
int a[N];
int pre[N];
int x[N];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cout.tie(0);
	int n=rdi(),m=rdi();
	for(int i=1;i<=n;i++)
	{
		a[i]=rdi();
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		pre[i]=pre[i-1]+(x[i]=a[i]);
	}
	int sz=unique(x+1,x+n+1)-x-1;
	int ans=0;
	for(int i=1;i<=sz;i++)
	{
		int v=x[i];
		int p=lower_bound(a+1,a+n+1,v)-a;
		int q=upper_bound(a+1,a+n+1,v)-a;
		int l=0,r=p-1;
		while(l<r)
		{
			int mid=(l+r)>>1;
			int now=v*(p-mid)-(pre[p]-pre[mid]);
			if(now>m)
			{
				l=mid+1;
			}
			else
			{
				r=mid;
			}
		}
		ans=max(ans,q-l-1);
	}
	cout<<ans;
	return 0;
}
//lpy