#include <bits/stdc++.h>

using namespace std;

int a[10000],b[300000],l=0,r=0;

int main()
{
	//freopen("card.in","r",stdin);
	//freopen("card.out","w",stdout);
	
	int n,m;
	cin >> n >> m;
	
	for(int i=0;i<n;i++)
	{
		cin >> a[i];
	}
	
	for(int l=0;l<n;l++)
	{
		for(int i=0;i<n;i++)
		{
			if(l!=0)
			{
				i++;
			}
			b[a[i]]++;
			if(b[a[i]]>1)
			{
				r=i;
				for(int j=l;j<r;j++)
				{
					b[a[j]]--;
				}	
				l=r;
			}
		}
	}
	
	for(int i=0;i<m;i++)
	{
		cout << b[i] << " ";
	}
	
	return 0;
}
