#include<bits/stdc++.h>
using namespace std;
int const N=2e5+5;
int a[N],f[N];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	memset(f,-1,sizeof(f));
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    	cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=min(i,m);j>=1;j--)
			f[j]=max(f[j],f[j-1]&a[i]);
	}
	//
	cout<<f[m];
} 
