#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<string>
using namespace std;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int a[n];
	for(int i=0;i<=n;i++)
	{
		cin >> a[i];
	}
    int b[n];
    for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=n;j++)
		{
		
		int h=0;
		if(a[i]==a[h])
		{
			b[i]+=1;
			h++;
		 } 
	  }
}
	sort(b+n,b+n+1);
	for(int i=0;i<=n;i++)
	{
		int q=n-1;
		int p=0;
		b[q]++;
		if(m<=0)
			{
				break;
			 
		if(b[q]==b[n])
		{
			m--;
			q--;
		
		p++;
		}
	}
	}
	cout << p;
	return 0;
 } 
