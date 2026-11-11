#include<bits/stdc++.h>
using namespace std;
char s[200000003];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	int n;
	cin>>n;
	int a=0;
	char c;
	int m=0;
	for(int i=0;i<n;i++)
	{
		cin>>a>>c;
		fill(s+m,s+m+a,c);
		m+=a;
	}
	int l=0,r=m-1;
	int mx=m/2;
	while(r>l)
	{
		if(s[l]==s[r])
		{
			mx--;
		}
		l++;r--;
	}
	cout<<mx;
	return 0;
}
