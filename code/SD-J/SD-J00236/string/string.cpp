#include<bits/stdc++.h>
using namespace std;
int n;
long long a[200005];
char c[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	int k=n;
	int st=1;
	long long ans=0;
	while(a[st]!=0)
	{
		if(c[st]==c[k])
		{
			if(a[st]>a[k])
			{
				a[st]-=a[k];
				a[k]=0;
				k--;
			}
			else if(a[st]==a[k])
			{
				a[st]=a[k]=0;
				k--;
				st++;
			}
			else
			{
				a[k]-=a[st];
				a[st]=0;
				st++;
			}
		}
		else
		{
			if(a[st]>a[k])
			{
				a[st]-=a[k];
				c[k]=c[st];
				ans+=a[k];
				a[k]=0;
				k--;
			}
			else if(a[st]==a[k])
			{
			
				c[k]=c[st];
				ans+=a[k];
				a[st]=a[k]=0;
				st++;
				k--;
			}
			else
			{
				a[k]-=a[st];
				ans+=a[st];
				a[st]=0;
				c[st]=c[k];
				st++;
			}
		}
	}
	cout<<ans;
	return 0;
}
//9:10
