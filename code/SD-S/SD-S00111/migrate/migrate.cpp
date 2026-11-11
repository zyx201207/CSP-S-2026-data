#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define fst ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

const int P=998244353;
const long long INF=0x3f3f3f3f3f3f3f3f;
const int N=1e6+10,M=2e6+10;

int conid,t;
int n;
long long a[M],f[M],l[M],k;
long long ans;

void solve()
{
	cin>>n>>k;
	ans=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int j=1;j<=n;j++)
	{
		f[j-1]=f[j]=l[j-1]=1;
		l[j]=0;
		for(int i=j-2;i>0;i--)
		{
			bool b1=(a[i+1]-a[i]<=k),b2=(a[i+2]-a[i]<=k);
			if(b1&&b2)
			{
				if(l[i+1]<l[i+2])
				{
					l[i]=l[i+1]+1;
					f[i]=f[i+1];
				}
				else if(l[i+1]>l[i+2])
				{
					l[i]=l[i+2]+1;
					f[i]=f[i+2];
				}
				else
				{
					l[i]=l[i+2]+1;
					f[i]=f[i+2]+f[i+1];
				}
			}
			else if(b1==1)
			{
				l[i]=l[i+1]+1;
				f[i]=f[i+1];
			}
			if(f[i]==2)
			{
				ans++;
			}
		}
	}
	cout<<ans<<endl;
}

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>conid>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}

