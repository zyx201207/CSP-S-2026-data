#include<bits/stdc++.h>
using namespace std;
long long x[2000005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout); 
	int c,t;
	cin>>c>>t;
	if(c==11||c==12)
	{
		int n;
		long long d;
		while(t--)
		{
			cin>>n>>d;
			for(int i=1;i<=n;i++)
			{
				cin>>x[i];
			}
			long long d2=x[2]-x[1];
			int val=d/d2;
			if(val<=1)
			{
				cout<<0<<endl;
			}else{
				cout<<max(n-2*val+1,0)<<endl;
			}
		}
	}
	return 0;
}
