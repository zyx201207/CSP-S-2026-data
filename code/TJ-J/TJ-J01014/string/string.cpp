#include<bits/stdc++.h>
using namespace std;
int a[1000000];
char ch[1000000];
string s;
int m[1000000];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	if(n==1)
	{
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>ch[i];
		m[i]=a[i];
	}
	for(int j=1; ;j++)
		{
		
		s=s+ch[i];
		if(s.size().n)
		{
			break;
		}
		}
	int zb=0;
	int yb=s.size()-1;
	int cnt=0;
	while(zb<yb)
	{
		if(ch[zb]!=ch[yb])
		{
			cnt++;
			zb++;
			yb--;
		}
	}
	cout<<cnt;
	return 0;
}
