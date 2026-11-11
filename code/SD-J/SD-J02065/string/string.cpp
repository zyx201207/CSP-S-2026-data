#include<bits/stdc++.h>
#include<cstdio>
char a[9100000];

using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,k=0;
	cin >> n;
	for(int i=1;i<=n;i++) 
	{
		int c;
		char d;
		cin >>c>>d;
		
		for(int i=1;i<=c;i++)
		{
			a[++k]=d;
		}
	}
	int cnt=0;
	
	for(int i=1;i<=(k+1)/2;i++)
	{
		if(a[i]!=a[k-i+1])
		{
			cnt++;
		}
	}
	cout <<cnt;
	return 0;
}
