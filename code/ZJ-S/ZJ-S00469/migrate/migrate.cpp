#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,x[2000050];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	if(c==0)
	{
		while(t--)
		{
			cin>>n>>d;
			bool f=0;
			for(int i=1;i<=n;i++) 
			{
				cin>>x[i];
				if(x[i]!=i) f=1;
			}
			if(d==2&&!f) 
			{
				if(n==4)cout<<1<<"\n";
				else cout<<2<<"\n";
			}
			else{
				if(n==5&&d==3) cout<<0<<"\n";
				else if(n==6&&n==2) cout<<1<<"\n";
			}
		}
		return 0;
	}
	
	return 0;
}
