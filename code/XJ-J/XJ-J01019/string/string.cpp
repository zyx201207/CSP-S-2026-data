#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	char o;
	int n,a,k=0;
	string p;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>o;
		for(int j=1;j<=a;j++)
		{
			p=p+o;
		}
	}

	for(int i=0;i<=p.size()/2;i++)
	{
		if(p[i]!=p[p.size()-1-i])
		{
			p[p.size()-i]=p[i];
			k++;
		}
	}
	cout<<k;
	return 0;
}