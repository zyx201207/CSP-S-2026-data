#include<bits/stdc++.h>
using namespace std;


int n;
int c,t,d;
int arr[2000005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;++i)
		{
			cin>>arr[i];
		}
		if(n%2==0)
		{
			int delta = arr[2]-arr[1];
			int l=4;
			int ans = 0;
			for(l;l<=n;l+=2)
			{
				if((l/2-1)*delta<d)
				{
					ans++;
				}
			}
			cout<<ans<<endl;
		}
		if(n%2==1)
		{
			n--;
			int delta = arr[2]-arr[1];
			int l=4;
			int ans = 0;
			for(l;l<=n;l+=2)
			{
				if((l/2-1)*delta<d)
				{
					ans++;
				}
			}
			cout<<ans*2<<endl;
		}
		
	}
	
	return 0;
}  
