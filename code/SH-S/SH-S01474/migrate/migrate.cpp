#include<bits/stdc++.h>
using namespace std;
long long c,t;
vector<vector<int> > r(100010); 
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int l=0;l<t;l++)
	{
		long long n,d,s[100010]={0},sum=0,ans=0;
		cin>>n>>d;
		long long a[100010];
		for(int i=0;i<n;i++)
			cin>>a[i];
		for(int i=0;i<n;i++)
			for(int j=i+1;j<n;j++)
			{
				bool b=0;
				if(a[j]-a[i]<=d)
					r[i].push_back(a[j]);
			}
		for(int i=0;i<n;i++)
		{
			for(long long j=i;j<r[i].size();j++)
			{
				for(long long k=j;k<=r[j].size();k++)
				{
					s[r[j][k]]++;
				}
			}
			for(long long j=0;j<n;j++)
				if(s[j])
					sum++;
			if(sum==2)
				ans++;
		} 
		cout<<ans<<endl;
	}
	return 0;
}
