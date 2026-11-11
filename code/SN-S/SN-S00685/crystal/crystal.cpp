#include <bits/stdc++.h>
using namespace std;
const int N= 1000005;
int n,m,a[N],num[N];
int main() 
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int ans=1;
	for(int i = 1;i<=n;i++)
	{
		cin>>a[i];	
	}

    for(int i = 2;i<=n;i++)
    {
    	num[i]=a[i]-a[i-1];
	}
	while(m>0)
	{
		for(int i = 2;i<=n;i++)
		{
			while(num[i]>0 && m>0)
			{
				num[i]--;	
				m--;
			}
		}
	}
	for(int i = 2;i<=n;i++)
	{
		if(num[i]==0)
		{
			ans++;
		}
	}
    cout<<ans;
	return 0;
}
