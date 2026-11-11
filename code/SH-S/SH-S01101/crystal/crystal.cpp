#include<bits/stdc++.h> 
using namespace std;
int n,a[500005];
long long m,ans=1;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d %lld",&n,&m);
	for(int i = 1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	sort(a,a+1);
	for(int i = 1;i<=n;i++)
	{
		if(m>0)
		{
			m-=a[i+1]-a[i];
			a[i]=a[i+1];
			ans++;
		}
		int j = i;
		while(j--&&m)
		{
			if(a[j-1]!=a[j])
			{
				m-=a[j]-a[j-1];
				a[j-1]=a[j];
			}
		}
	}
	cout <<ans;
	return 0;
}
