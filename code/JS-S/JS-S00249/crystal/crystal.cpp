#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],ans=0;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		long long j=i,m2=m;
		while(m2>=0&&j<n)
		{
			j++;
			m2-=(j-i+1)*(a[j]-a[j-1]);
		}
		ans=max(ans,j-i+1);
	}
	cout<<ans;
	return 0;
}
