#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
int a[N];
ll ans;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=29;i>=0;i--)
	{
		int cnt=0;
		for(int j=1;j<=n;j++)
		{
			int wasd=a[j];
			wasd=wasd>>i;
			if(wasd%2==1)
			{
				cnt++;
			}	
		}
		if(cnt>=m)
		{
			ans=ans+pow(2,i);	
			for(int j=1;j<=n;j++)
			{
				int wasd=a[j];
				wasd=wasd>>i;
				if(wasd%2==0)
				{
					a[j]=0;
				}	
			}
		}		
	} 
	cout<<ans;
	return 0;
}
