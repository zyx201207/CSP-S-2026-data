#include<iostream>
#define ll long long
using namespace std;
const int N=2e6+5;
int c,t;
ll x[N];
int f(int l,int r,ll p)
{
	for(int i=r;i>=l;i--)
	{
		if(x[i]<=p) return i;
	}
	return l;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		int n;
		ll ans=0;
		ll d;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		for(int l=1;l<=n;l++)
		{
			for(int r=l+3;r<=n;r++)
			{
				int lk=l,cnt=0;
				int k=f(l,r,x[lk]+d);
				if(k==l) break;
				while(k<r)
				{
					int nk=f(k,r,x[k]+d);
					if(nk<=k) break;
					if(nk>=r) nk=r;
					for(int i=lk+1;i<k;i++)
					{
						if(x[i]-x[lk]<=d&&x[nk]-x[i]<=d) cnt++;
					}
					if(cnt>1) break;
					lk=k;
					k=nk;
				}
				if(cnt==1&&k>=r) ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

