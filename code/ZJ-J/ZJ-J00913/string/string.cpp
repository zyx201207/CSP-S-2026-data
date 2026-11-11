#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	char a[1000000];
	int n;
	
	cin>>n;
	int j=0;
	int m=0;
	for(int i=0;i<n;i++)
	{
		int a1;
		char c;
		cin>>a1>>c;
		m+=a1;
		for(int z=j;z<i+a1;z++)
		{
			a[z]=c;
			j++;
		}
	}
	
	int cnt=0;
	
	for(int i=0;i<m/2;i++)
	{
		if(a[i]!=a[m-i-1])
		{
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}