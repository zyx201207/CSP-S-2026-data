#include<bits/stdc++.h>
using namespace std;
int a[500005],b[300005]={0};
int main()
{
	fropen("card.in","r",stdin);
	fropen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]; 
	}
	for(int i=1;i<=n;i++)
	{
			int t=i,w=t;
			while(t<=w&&w<=n)
			{
				if(a[t]==a[w]&&t!=w)
				{
					for(int k=t;k<=w-1;k++)
					{
						if(b[a[k]]!=0)b[a[k]]--;
					}
					t=w;
				 } 
				 b[a[w]]++;
				 w++;
			}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<b[i]<<" ";
	}
	return 0;
}
