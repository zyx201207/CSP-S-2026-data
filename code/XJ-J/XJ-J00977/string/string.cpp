#include<bits/stdc++.h>
using namespace std;
long long n,a,i,k,t,r,v;
char s[10000000],c;
int main()
{
	freopen("string.in","f"stdin);
	freopen("string.out","x"stdout);
	cin>>n;
	while(n--)
	{
		cin>>a>>c;
		while(a--)
		s[k++]=c;
	}
	t=0;r=k-1;
	while(t<r)
	{
		if(s[t]!=s[r])
		{
			s[r]=s[t];
			v++;
		}
		t++;r--;
	}
	cout<<v;
	return 0;
}