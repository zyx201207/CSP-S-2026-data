#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int b[200005]
	for(int i=0;i<n;i++)
	{
		cin>>b[i];
	}
	int v=INT_MIN;
	if(m==n)
	{
		for(int i=0;i<m;i++)
		{
			v&=b[i];
		}
		cout<<v;
	}
	else
	{
		for(int i=0;i<n;i+=m)
		{
			int j=m;
			while(j>0)
			{

			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
