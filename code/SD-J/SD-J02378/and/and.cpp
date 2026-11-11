#include <bits/stdc++.h>
using namespace std;
/*
string get_2(long long x)
{
	char c[101];
	for(int i=0;i<=100;i++)
		c[i]='0';
	int cnt=1;
	long long xx=x;
	while(xx)
	{
		c[cnt]='0'+(x%2);
		x/=2;
		cnt++;
	}
	string s="";
	for(int i=cnt;i>=1;i--)
	{
		s+=c[i];
	}
	return s;
}
*/


int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long maxx=-100;
	int n,m;
	cin >> n >> m;
	int a[200000+2];
	//string b[200000+2];
	/*
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		b[i]=get_2(a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		long long min=1e8;
		
		for(int j=0;j<min;j++)
		{
			
		}
	}
	*/
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	for(int i=1;i<n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if((a[i]&a[j])>maxx)
			{
				maxx=a[i]&a[j];
			}
		}
	}
	cout << maxx;
	
	
	return 0;
}
