#include<bits/stdc++.h>
using namespace std;
int n,a[500005],b[500005],f[500005],cnt,c[500005],s[500005],m;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=n;i>=1;i--)
	{
		if(i==n)
		{
			f[i]=i;
		}
		else f[i]=f[i+1]-1;
		if(b[a[i]]==0)
		{
			b[a[i]]=i;
		}
		else 
		{
			f[i]=0;
		}
		s[a[i]]+=f[i];
	}
	for(int i=1;i<=m;i++)cout<<s[i]<<" ";
	return 0;
}
