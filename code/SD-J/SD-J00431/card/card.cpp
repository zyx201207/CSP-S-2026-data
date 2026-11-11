#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
int a[maxn],t[maxn];
int fl[maxn];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		t[a[i]]++;
	}
	if(n<=5 && m<=2)
	{
		if(m==1)
		{
			cout<<n; 
		}
		else
		{
			for(int i=1;i<=m;i++)
			{
				if(fl[i]==0)
				{
					for(int j=n;j>=1;j--)
					{
						if(a[j]==i)
						{
							cout<<j<<" ";
							fl[i]=1;
							break;
						}
					}		
				}						
			}
		}
	}
	else
	{
		for(int i=1;i<=m;i++)
		{
			if(a[n]==i)
			{
				cout<<n<<" ";
			}
			else
			{
				cout<<t[i]<<" ";
			}
		}
	}		
	return 0;
} 
