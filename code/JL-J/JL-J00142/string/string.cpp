#include<bits/stdc++.h>
using namespace std;
string x,y,ty,f;
int w[100000005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,k=0,s=0,lj=INT_MAX;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		long long a;
		string c;
		cin>>a;
		cin>>c;
		ty+=c;
		k+=a;
		for(int j=0;j<a;j++)
		{
			x+=c;
		}
	}
	y=x;
	f=x;
	reverse(y.begin(),y.end());
	if(x==y)
	{
		cout<<0<<'\n';
		return 0;
	}
	for(int j=0;j<n;j++)
	{
		x=f;
	for(int i=0;i<k;i++)
	{
		if(x[i]!=y[i])
		{
			if(x[i]!=ty[j])
			{
				s++;
			}
		}
	}
	if(lj>s)
	{
		lj=s;
	}
	s=0;
	}	
	cout<<lj<<'\n';
	return 0;
}
