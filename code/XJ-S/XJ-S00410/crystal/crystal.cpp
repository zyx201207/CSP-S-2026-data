#include<bits/stdc++.h>
using namespace std;
const long long N=5e7+5;
long long m,n,ans2=0,a[N];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i]; 
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++)
	{
		long long cnt=0,ans=1;
		for(int j=i-1;j>=1;j--)
		{
			cnt+=a[i]-a[j];
			if(cnt<=m)
			{ 
				ans++; 
			}
			else
				j=0;
		} 
		if(ans2<ans)
			ans2=ans;
	}
	
	cout<<ans2;
	
}
