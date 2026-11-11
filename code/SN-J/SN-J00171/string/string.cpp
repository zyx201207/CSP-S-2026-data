#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,m=0;
	cin >>n;
	int a[1000000]; 
	string b;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		cin>>b[i];
	}
    for(int i; i<=n;i++)
    {
    	m=a[i]+n;
	}
	m=m/2;
	cout<<m;
	return 0;
 } 
