#include<bits/stdc++.h>
using namespace std;
long long int i,j,n,a[10000005],m,p[10000005],vel[10000005];

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	stack<long long int> q;
		for(i=1;i<=n;i++)
		{
			cin>>a[i];
			if(vel[a[i]]==0)
			vel[a[i]]=i;
		}
	for(i=1;i<=m;i++)
	{
		cout<<n-vel[i]+1<<" ";
	}
	return 0;
}