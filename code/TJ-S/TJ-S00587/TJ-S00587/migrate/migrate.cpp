#include <bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int c,t;
long long a[N];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>t;
	while(t--)
	{
		bool bo=false;
		long long n,d;
		cin>>n>>d;
		memset(a,0,sizeof(a));
		for(int i=1;i<=n;i++) 
		{
			cin>>a[i];
			if(a[i]-a[i-1]>d) 
			{
				bo=true;
				break;
			}
		}
		if(bo) 
		{
			cout<<0<<"\n";
			continue;
		}
		long long k=a[2]-a[1];
		long long p=a[n]-a[1];
		if(d/k==2) cout<<n-3<<"\n";
		else if((p<=2*d+1)||(p<=10*d)) cout<<n/2<<"\n";
		else cout<<0<<"\n";
	}
	return 0;
}
