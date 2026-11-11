#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=2e6+10,inf=1e18;
int n,d,ccc;
int a[N],lst1[N],pre1[N];
int f[510][510],g[N],ans[N];
int get_last(int x)
{
	int tmp=a[x]+d;
	int l=x,r=n,res=0;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(a[mid]>tmp)
			r=mid-1;
		else
			l=mid+1,res=mid;
	}
	return res;
}
int get_pre(int x)
{
	int tmp=a[x]-d;
	int l=1,r=x,res=0;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(a[mid]>=tmp)
			res=mid,r=mid-1;
		else
			l=mid+1;
	}
	return res;
}
void clean()
{
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			f[i][j]=0;
}
void solve()
{
	cin>>n>>d;
	a[0]=-inf;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(ccc<=10)
	{
		for(int i=1;i<=n;i++)
		{
			lst1[i]=get_last(i);
			pre1[i]=get_pre(i);
		}
		int sum=0;
		for(int l=1;l<=n;l++)
		{
			for(int r=l+1;r<=n;r++)
			{
				clean();f[l][0]=1;
				for(int i=l;i<=r;i++)
					for(int j=0;j<=n;j++)
						for(int k=i+1;k<=min(lst1[i],r);k++)
							f[min(k,r)][j+1]+=f[i][j];
//				for(int i=l;i<=r;i++,cout<<"\n")
//					for(int j=0;j<=n;j++)
//						cout<<f[i][j]<<" ";
//				cout<<"\n";
				for(int j=0;j<=n;j++)
				{
					if(f[r][j])
					{
						sum+=(f[r][j]==2);
						break;
					}
				}
			}
		}
		cout<<sum<<"\n";
	}
	else
		cout<<0<<"\n";
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int t;
	cin>>ccc>>t;
	while(t--)
		solve();
	return 0;
}