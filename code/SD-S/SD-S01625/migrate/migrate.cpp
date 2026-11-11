#include<bits/stdc++.h>
#define endl "\n"
#define int long long
using namespace std;
const int N=5005;
int c,t,n,d,ans,x[N],a[N];
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--)
	{
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		for(int i=1;i<=n;i++)
		{
			int la=i;
			a[i]=1;
			for(int j=i+1;j<=n;j++)
			{
				if(x[j]-x[j-1]>d) break;
				if(x[j]-x[la]>d) la=j-1;
				if(la-2>=i&&x[j]-x[la-2]<=d) a[j]=3;
				else if(la-1>=i&&x[j]-x[la-1]<=d) a[j]=min(a[la]+a[la-1],3ll);
				else a[j]=a[la];
				if(a[j]==2) ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;	
} 
