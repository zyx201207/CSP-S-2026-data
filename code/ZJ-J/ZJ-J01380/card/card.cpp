#include<bits/stdc++.h>
using namespace std;

const int N=5e5+5;
const int M=3e5+5;

int a[N];
int b[N];
int ans[M];

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n,m,nn;
	cin>>n>>m;
	nn=n;
	
	if(m==1)
	{
		cout<<n;
		return 0;
	}
	
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=-1;
	}
	
	int pl;
	while(n--)
	{
		for(int i=1;i<=n;i++)
		{
			b[i]=-1;
		}
		
		pl=nn-n;
		while(pl<=nn)
		{
			b[pl]=a[pl];
			
			for(int i=pl-1;i>=1;i--)
			{
				if(b[pl]==b[i])
				{
					for(int j=pl-1;j>=i;j--)
					{
						b[j]=-1;
					}
					break;
				}
			}
			pl++;
		}
		
		for(int i=1;i<=nn;i++)
		{
			if(b[i]!=-1)
			{
				ans[b[i]]++;
			}
		}
	}
	
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<" ";
	}
	
	return 0;
}
