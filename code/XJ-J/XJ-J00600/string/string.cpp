#include<bits/stdc++.h>
using namespace std;
long long int n,i,a,k,t,j,z,x,l,r,middle;
char c[200005],b,m[200005];
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while(n--)
	{
		cin>>a;
		cin>>b;
		for(i=1;i<=a;i++)
		c[++k]=b;
	}
	l=1;r=k;
	middle=(l+r)/2;
	if(middle%2==0)
	{
		for(l=1;l<=middle;l++)
		{	
			for(r=strlen(c);r>=middle;r--)
			{
				if(c[l]!=c[r])
				t++;
			}
		}
	}
	cout<<t;
}