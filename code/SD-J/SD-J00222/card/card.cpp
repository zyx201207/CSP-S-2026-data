#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[200005],b[200005];
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,a2=-1,cnt=1,y=-1;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
	y=i;
		cin>>a[i];
		if(a2!=a[i])
		{
			if(y!=-1)
			b[a[i]]=y;
			
		}
	}
	for(int i=1;i<=a[n];i++)
	{
		cout<<b[i]<<" ";
	}
	return 0;
}
