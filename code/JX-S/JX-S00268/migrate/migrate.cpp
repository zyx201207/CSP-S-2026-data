#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int c,t,n,d;
	cin>>c>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n>>d;
		int x[n+2];
		for(int j=1;j<=n;j++) cin>>x[j];
		if(c==11||c==12)
		{
			int p=x[n]-x[n-1];
			int q=d/p;
			if(q<=1) cout<<"0"<<endl;
			else if(q==2) cout<<(n-1)*(n-2)/2;
			else cout<<n*(n-1)/2;
		}
	}
	return 0;
}
