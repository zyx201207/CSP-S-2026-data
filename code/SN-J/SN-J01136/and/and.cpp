#include<bits/stdc++.h>
using namespace std;
int aa[200005];
int mx=0;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		int op;
		cin>>op;
		aa[i]=op;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			mx=max(mx,aa[i]&aa[j]);
		}
	}
	cout<<mx;
	return 0; 
}
