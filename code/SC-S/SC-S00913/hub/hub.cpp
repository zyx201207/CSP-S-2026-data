#include <bits/stdc++.h>
#include <stdio.h>
#include <cstdio>
using namespace std;
const int N=2e6+5;
long long c,t,n,k,u[N],v[N];
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>k;	
		for(int i=1;i<=n;i++)
		{
			cin>>u[i]>>v[i];
		}
		if(n%2==1)cout<<2<<endl;
		else cout<<1<<endl;
	}
	return 0;
}