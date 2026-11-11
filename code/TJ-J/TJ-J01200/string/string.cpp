#include<bits/stdc++.h>
using namespace std;
int bz=0,n;
char c;
long long z,a,sum=0;
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a>>c;
		if(a>1000000)
		{
			bz=1;
			z=z+a;
			for(int j=i;j<n-1;j++)
			{
				cin>>a>>c;
				z=z+a;
			}
			break;
		}
		for(int j=0;j<a;j++)
		{
			s=s+c;
		}
	}
	if(bz==0)
	{
		n=s.size();
		for(int i=0;i<n/2;i++)
		{
			if(s[i]!=s[n-1-i])
			{
				sum++;
			}
		}
		cout<<sum;
	}
	else
	{
		cout<<z/2;
	}
	return 0;
}
