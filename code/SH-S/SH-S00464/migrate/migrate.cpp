#include<bits/stdc++.h>
using namespace std;
int c,t;
long long x[2000005];
long long a[2000005];
long long check(long long i,long long d)
{
	if(a[i]==-1) return -114514;
	int sum=0;
	for(int j=i-d;j<i;j++)
	{
		if(a[j]==-1) return -1;
		sum+=a[j];
	}
	return sum;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>t;
	//Trick||Treat!
	while(t--)
	{
		long long cnt=0;
		memset(x,-1,sizeof(x));
		memset(a,-1,sizeof(a));
		long long n,d;
		cin>>n>>d;
		for(long long i=1;i<=n;i++) cin>>x[i];
		for(long long i=2;i<=n;i++)
		{
			for(long long j=1;j<i;j++)
			{
				if(x[j]+d>=x[i])
				{
					a[i]=j;
					break;
				}
			}
		}
		for(long long i=d+1;i<=n;i++)
		{
			if(check(i,d)==a[i]) cnt++;
		}
		cout<<cnt<<endl;
	}
	return 0;
}
