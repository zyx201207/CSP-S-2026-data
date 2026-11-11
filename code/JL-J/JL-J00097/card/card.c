#include<bits/stdc++.h>
using namespace std;
int main()
{
	int i,n.m;
	vector<int> a[1000],b[1000]=' ';
	cin>>n>>m;
	for(int j=0;j<n;j++)
	{
		cin>>a[j];
	}
	for(i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
				if(b.find(j)==0)
				{
					b.push_back(j);
				}
				else
				{
					b.pop(b[b.find(j)],b[n]);
				}
		}
		if(b.find[i]!=0)
		{
			 cout<<i<<" ";
		}
	}
	return 0;
}
	


