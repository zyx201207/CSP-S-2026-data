#include <iostream>
using namespace std;
long long n,m;
long long a[500005];
long long mp[500005];
long long ans[500005];
struct bone
{
	long long f;
	long long w;
};
bone c[500005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(long long i=1; i<=n; i++)
		{
			cin>>a[i];
		}
	for(long long i=1; i<=n; i++)
		{
			long long p=1;
			for(long long j=i; j<=n; j++)
				{
					mp[p]=a[j];
					if(c[a[j]].f==1)
						{
							for(long long x=c[a[j]].w; x<p; x++)
								{
									c[mp[x]].f=0;
									c[mp[x]].w=-1;
									mp[x]=0;
								}
							c[a[j]].f=1;
							c[a[j]].w=p;
							p++;
						}
					else
						{
							c[a[j]].f=1;
							c[a[j]].w=p;
							p++;
						}
				}
			for(long long j=1; j<=p; j++)
				{
					if(mp[j]!=0)
						{
							ans[mp[j]]++;
						}
				}
			for(long long i=1; i<=n; i++)
				{
					mp[i]=0;
				}
			for(long long j=1; j<=m; j++)
				{
					c[j].f=0;
					c[j].w=-1;
				}
		}
	for(long long i=1; i<=m; i++)
		{
			cout<<ans[i]<<' ';
		}
	cout<<endl;
	return 0;
}
