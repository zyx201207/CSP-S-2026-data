#include<bits/stdc++.h>
using namespace std;
long long int n,m,a[500005],v[500005],s=1,k=0;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
	scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	v[1]=1;
	for(int i=1;i<=n;i++)
	{
		while(a[i]!=a[i+1]&&m!=0)
		{
			int flag=0;
			for(int j=1;j<=n;j++)
			{
				if(v[j]==1&&m!=0)
				{
					a[j]++;
					m--;
					if(m==0)
					{
						flag=1;
						break;
					}
				}
			}
			if(a[i]==a[i+1])
			{
				v[i+1]=1;
				v[i]=1;
				s++;
			}
		}
	}
	for(int i=1;i<=n;i++)
	if(a[i]==a[i-1])
	v[i]=1;
	for(int i=1;i<=n;i++)
	if(v[i]==1)
	k++;
	cout<<k;
	return 0;
}
