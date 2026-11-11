#include <bits/stdc++.h>
using namespace std;
int q[1000000];
int n[1000000];
int main()
{
	freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
	int n,cnt=0;
	char db;
	string d[10000]={};
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int a;
		char c;
		cin>>a>>c;
		d[i]=c;
    }
    for(int i=1;i<=n;i++)
	{
		if(d[i]==d[i+1])
		{
			cout<<0;
			break;
	    }
		else
		{
			cout<<2;
			break;
	    }
	}
	return 0; 
}
