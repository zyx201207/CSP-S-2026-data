#include<bits/stdc++.h>
using namespace std;
int a[200005];
string s[200005];
bool abc(string x)
{
	for(int i=0;i*2<x.size();i++)
	{
		if(x[i]!=x[x.size()-i-1])
		{
			return 0;
		}
	}
	return 1;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,sum=0;
	string z="";
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>s[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=a[i];j++)
		{
			z+=s[i];
		}
	}
	if(abc(z))
	{
		cout<<"0";
	}
	else{
		for(int i=0;i<z.size();i++)
		{
			if(z[i]!=z[z.size()-i-1])
			{
				z[z.size()-i-1]=z[i];
				sum++;
			}
		}
		if(abc(z))
		{
			cout<<sum;
		}
	}
	return 0;
}
