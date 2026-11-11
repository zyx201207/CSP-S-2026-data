#include<bits/stdc++.h>
#define int long long
using namespace std;

const int M=2e6+10,INF=4e18;
int n,d,a[M];
int f[M],tot[M];

void work()
{
	scanf("%lld%lld",&n,&d);
	int ans=0;
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	a[n+1]=INF;
	
	if(n>=1e6)
	{
		printf("0\n");
		return;
	}
	
	for(int s=1;s<=n;s++)
	{
		for(int j=1;j<=n;j++)
			f[j]=INF,tot[j]=0;
		f[s]=0;
		
		for(int i=s;i<=n;i++)
		{
			for(int j=i+1;a[j]-a[i]<=d&&j<=n;j++)
			{
				if(f[j]==f[i]+1)
					tot[j]++;
				if(f[j]>f[i]+1)
				{
					f[j]=f[i]+1;
					tot[j]=1;
				}
			}
		}
		
//		cout<<"T: "<<s<<endl;
//		for(int i=1;i<=n;i++)
//			cout<<f[i]<<" ";
//		cout<<endl;
//		for(int i=1;i<=n;i++)
//			cout<<tot[i]<<" ";
//		cout<<endl;
		
		for(int i=1;i<=n;i++)
			if(tot[i]==2)
				ans++;
	}
	printf("%lld\n",ans);
//	cout<<endl;
}

signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int id,T;
	cin>>id>>T;
	while(T--)
		work();
	
	return 0;
}