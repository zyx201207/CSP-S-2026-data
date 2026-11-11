#include<bits/stdc++.h>
using namespace std;
long long a[500010],n,m,ans;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int mid=n/2+1;
	int o=a[mid];
	while(m>=0)
	{
		int x1=a[mid-1];
		int x2=a[mid];
		if(m<=0 || mid<=1 || x1+m<x2) break;
		if(x1+m>=x2)
		{
			m=m-(x2-x1);
			a[mid-1]=a[mid];
			mid--;
		}
	}
	for(int i=1;i<=n;i++)
		if(a[i]==o) ans++;
	cout<<ans;
	return 0;
}
