#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("card2.in","r",stdin);
//	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n],c[n];
	for(int i=0;i<n;i++)
	{
	cin>>a[i];
	}
	int s[m+1];
	int f[m+1];
	fill(f,f+m+1,0);
	for(int i=0;i<n;i++)
	{
		fill(s,s+m+1,-1);
		fill(c,c+n,0);
		int ic=0;
		for(int j=i;j<n;j++)
		{
			if(s[a[j]]==-1)
			{
				c[ic]=a[j];
			}
			else{
				for(int y=s[a[j]]+1;y<ic;y++)
				{
					s[c[y]]=-1;
				}
				ic=s[a[j]];
			}
			s[a[j]]=ic;
			ic++;
			
			
		}
	
		for(int e=0;e<ic;e++)
		{
			f[c[e]]++;
		}
	}
	for(int i=1;i<m+1;i++)
	{
		cout<<f[i]<<" ";
	}
	return 0;	
}
