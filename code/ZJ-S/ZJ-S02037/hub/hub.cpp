#include<bits/stdc++.h>
using namespace std;
int c,T,n,m,x,y,a[2000005],i;
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>T;
	while(T--)
	{
		cin>>n>>m;
		for(i=1;i<=n-1;i++)
		{
			cin>>x>>y;
			a[i]=abs(x-y);
		}
		sort(a+1,a+n);
		cout<<a[m]<<"\n";
	}
	return 0;
}
