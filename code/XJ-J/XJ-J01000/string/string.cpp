#include<bits/stdc++.h>
using namespace std;
long long d=0;
bool q(string x,string y)
{
	bool z=false;
	for(int i=0;i<d/2;i++)
	{
		z=false;
		if(x[i]!=y[i])
		{
			z=true;
			return z;
		}
	}
	return 0;
}
int main()
{
	freopen("string","r",stdin);
	freopen("string","w",stdout);
	long long n=0,sum=0;
	cin>>n;
	long long a[n+1]={0};
	char c[n+1]={0};
	string s;
	string l;
	string r;
	for(int i=0;i<n;i++)
	{
		cin>>a[i]>>c[i];
		for(int j=a[i];j>0;j--)
		{
			s+=c[i];
		}
		d+=a[i];
	}
	if(d==1)
	{
		cout<<0;
	}else{
		if(d%2==0)
		{
			for(int i=0;i<d/2;i++)
			{
				l+=s[i];
			}
			for(int i=d-1;i>=d/2;i--)
			{
				r+=s[i];
			}
		}else{
			for(int i=0;i<d/2;i++)
			{
				l+=s[i];
			}
			for(int i=d-1;i>d/2;i--)
			{
				r+=s[i];
			}
		}
		for(int i=0;i<d/2;i++)
		{
			if(q(l,r))
			{
				sum++;
			}
		}
		cout<<sum;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}