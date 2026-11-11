#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	int a[200005];
	char b[200005];
	string c;
	cin>>n;
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
		cnt+=a[i];
		for(int j=1;j<=a[i];j++)
		{
			c+=b[i];
		}
	}
	char m=b[1];
	int g=0;
	for(int i=1;i<=n;i++)
	{
		if(b[i]==m) g++;
	}
	if(g==n) cout<<0;
	else
	{
		if(cnt%2!=0) cnt+=1;
		int d=cnt/2;
		int r=0;
		for(int i=1;i<=d;i++)
		{
			if(c[i]!=c[c.size()-i+1]) r++;
		}
		cout<<r;
	}
	
	
	
	
	
	return 0;
}
