#include <bits/stdc++.h>
using namespace std;
int n;
long long m,a[500005],b[500005],ans;
int main()
{
	freopen("crystal.in","r","stdin");
	freopen("crystal.out ","w","stdout"); 
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	if(n%2)
	{
		for(int i=1;i<=n;i++)			
			b[i]=abs(a[i]-a[n/2+1]);
		sort(b+1,b+n+1);
		for(int i=1;i<n;i++)
		{
			m-=b[i];
			if(m<0)
				break;
			ans++;
		}
		cout<<ans;
		return 0;
	}
	else
	{
		for(int i=1;i<=n;i++)			
			b[i]=abs(a[i]-a[n/2+1]);
		sort(b+1,b+n+1);
		for(int i=1;i<n;i++)
		{
			m-=b[i];
			if(m<0)
				break;
			ans++;
		}
		cout<<ans;
		return 0;
	}
	return 0; 
} 