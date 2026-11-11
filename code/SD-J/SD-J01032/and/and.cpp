#include<bits/stdc++.h>
using namespace std;
int n,m,ans=-1e9,que;
long long a[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int k=j;k<=n;k++)
			{
				int b=a[j]/2;
				if(a[j]>a[k]) que=a[j];
				else que=a[k];
			}
		}
		if(ans<que) ans=que;
	}
	cout<<ans<<"\n";
	return 0;	
}
