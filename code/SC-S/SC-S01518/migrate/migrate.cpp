#include<bits/stdc++.h>
using namespace std;
long long  c,t,n,d,s,ans;
long long x[100000],b[100000];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int v=0;v<t;v++)
	{
		ans=0;
		cin>>n>>d;
		for(int i=0;i<n;i++)
		{
			cin>>x[i];
			int an=0;
			for(int j=0;j<i;j++)
			{
				if(x[j]-x[i]<=d&&s<=b[j])
				{
					if(s==0)s=b[i];
					b[i]=b[j]+1;
					if(s==b[j])
					{
						an++;
					}
				}
				if(an==2)
				{
					ans++;

				}
			}
		}
		cout<<ans;
	}
} 