#include<iostream>

#define ll long long
using namespace std;
ll n,d,a[2000005],aa[2000005],mxlen[2000005],ans=1;
int c,t;

void solve()
{
	ll sum=0;ans=1;
	for(int i=1;i<=n;i++)
	{
		if(mxlen[i]==2){sum++;}
		else if(sum)
		{
			ans*=(sum-1);
			sum=0;
		}
	}
	if(sum)ans*=(sum-1);
}

int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie();cout.tie();
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		cin>>a[1];
		for(int i=2;i<=n;i++)
		{
			cin>>a[i];
			aa[i-1] = a[i] - a[i-1];
		}
		aa[n] = 2*d;
		//for(int i=1;i<=n;i++)cout<<aa[i]<<" ";
		//cout<<"\n\n";
		int j=1,sum=aa[1];
		for(int i=1;i<=n;i++)
		{
			while(j<n && sum<=d)
			{
				j++;
				sum += aa[j];
			}
			//cout<<i<<","<<j-1<<"\n";
			mxlen[i] = j-i;
			sum-=aa[i];
		}
		//for(int i=1;i<=n;i++)cout<<mxlen[i]<<" ";
		solve();
		cout<<ans<<"\n";
	}
	return 0;
}