#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],ans,MAX;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	ans=1;MAX=0;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		ans=1;
		for(int j=i+1;j<=n;j++)
		{
			if((a[j]-a[i])*(j-1)<=m)
			{
				m=m-(a[j]-a[i])*(j-1);
				ans++;
				a[i]=a[j];
			}
			MAX=max(MAX,ans);
		}
	}
	cout<<MAX<<endl;
	return 0;
}
