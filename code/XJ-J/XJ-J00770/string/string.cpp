#include<bits/stdc++.h>
using namespace std;
char c[100],d[100];
int i,n,a[100],s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		d[i]=c[i]-'0';
		if(c[i]!=d[i])
		{
			s++;
		}
	}
	cout<<s;
}