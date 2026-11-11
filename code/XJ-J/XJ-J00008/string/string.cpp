#include<bits/stdc++.h>
using namespace std;
long long int i,n,a;
char c,s[100000000],l,m,b[1000000],c[1000000];
int main()
{
	freopen("string","r",stdin);
	freopen("string","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a>>c;
		while(a!=0)
		{
			s[++l]=c;
			a--;
		}
	}

	for(i=1,l='\n';i>=l;i++,l--)
	{
		if(a[i]!=a[l])
		m++;
	}
	cout<<m-1;
}