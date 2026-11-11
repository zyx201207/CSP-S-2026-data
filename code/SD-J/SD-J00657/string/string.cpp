#include<bits/stdc++.h>
using namespace std;
long long a[200001],n,s=0;
char c[200001];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		cin>>c[i];
	}
	long long r=n;
	for(int i=1;i<r;i++)
	{
		if(a[i]!=0)
		{
			if(a[r]!=0)
			{
				if(c[i]!=c[r])
				{
					s++;
				}
				a[i]--;
				a[r]--;
			}
			else
			{
				r--;
			}
			i--;
		}
	}
	cout<<s;
	return 0;
} 
