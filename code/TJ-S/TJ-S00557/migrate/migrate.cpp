#include<bits/stdc++.h>
using namespace std;
const int N=2e6+99;
typedef long long ll;
int c,t;
ll n,d;
ll x[N];
bool f=1;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);

	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		f=1;
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];
			if(i>2&&x[i]-x[i-1]!=x[i-1]-x[i-2])f=0;
		}
		if(f)
		{
			ll diff=x[2]-x[1];
			ll m=d/diff;
			if(m<=1)
			{
				cout<<0<<endl;
			}
			else
			{
				ll ans=max(0ll,n-(2*m-1));
				cout<<ans<<endl;
			}
		}
		else if(x[n]-x[1]<=10*d)
		{
			cout<<n-2<<endl;
		}
		
	}
	return 0;
}
