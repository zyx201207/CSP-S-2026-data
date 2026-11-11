#include<bits/stdc++.h>
using namespace std;
char a[200005];
char s;
int n,c;
int ii=1;
long long ans;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>c;
		cin>>s;
		for(int j=1;j<=c;j++)
		{
			a[ii]=s;
			ii++;
		}
	}
	long long len=ii-1;
	for(int i=1;i<=len/2;i++)
	{
		if(a[i]!=a[len-i+1])
		{
			ans++;
		}
	} 
	cout<<ans;
	
	return 0;
}

