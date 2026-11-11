#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n,d;
const int N=2e6+5;
vector<int> q[N];
int a[N],dis[N],ans=0,cnt[N];
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		memset(cnt,0,sizeof(cnt));
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		if(d!=2*(a[2]-a[1])) cout<<0<<endl;
		if(d==2*(a[2]-a[1]))
		{
			cout<<n-3<<endl;
		} 
	}
	return 0;
 } 
