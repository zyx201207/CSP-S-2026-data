#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	long long js=0,ss=0,a[200000],cc;
	char c[200000],z[250000];
	for (int i=0;i<n;i++)
	{
		cin>>a[i]>>c[i];
		js+=a[i];
		for(int j=js-a[i];j<js;j++)
		{
			cc=c[i];
			z[j]=cc;
		}
			
	}
	for(int i=0;i<js/2;i++)
	{
		if(z[i]==z[js-1-i])
		{
			
		}
		else
		{
			ss++;
		}
		

	}
	cout<<ss;
	return 0;
 } 
