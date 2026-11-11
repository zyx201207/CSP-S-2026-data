#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+10;
int n;
int d;
int x[N];
int lst[N];
int f1[N],f2[N];
int s1[N],s2[N];
void solve()
{
	cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>x[i];
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
			lst[j]=upper_bound(x+1,x+i+1,x[j]+d)-x-1;
		for(int j=i+1;j<=n;j++) lst[j]=0;
		for(int j=1;j<i;j++)
		{
			int x=j;
			int cnt=0;
			while(x<i)
			{
				if(lst[lst[x]]==lst[lst[x]-1]&&lst[lst[x]]!=0) cnt++;
				x=lst[x];
			}
			if(cnt==1) ans++;
		}
	}
	cout<<ans-n<<endl;
}

signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;
	cin>>c>>T;
	while(T--) solve();
	return 0;
 }

