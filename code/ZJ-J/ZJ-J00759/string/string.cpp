#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+2;
#define int long long

signed a[N];
char c[N];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	
	
	int ans=0,atl=1,atr=n;
	
	while(atl<=atr)
	{
		if(a[atl]<a[atr])
		{
			if(c[atl]!=c[atr])
			{
				ans+=a[atl];
			}
			a[atr]-=a[atl];
			atl++;
		}
		else if(a[atl]>a[atr])
		{
			if(c[atl]!=c[atr])
			{
				ans+=a[atr];
			}
			a[atl]-=a[atr];
			atr--;
		}
		else
		{
			if(c[atl]!=c[atr])
			{
				ans+=a[atr];
			}
			atr--;
			atl++;
		}
	}
	cout<<ans;
}
//1000000000