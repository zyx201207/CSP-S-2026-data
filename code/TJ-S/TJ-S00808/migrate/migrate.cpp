#include<bits/stdc++.h>
using namespace std;
long long n,d;
const int N=2e6+10;
int flag=1;
long long a[N];
int zhishu(long long x,long long y)
{
	if(x==2||x==1) return true;
	for(int i=2;i<=sqrt(x);i++)
	{
		if(x%i==0&&i<=y) return false;
	}
	return true;
}
void solve2()
{

	long long ans=0;
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(abs(a[j]-a[i])<=d||j-i==1) continue;
			else
			{
			//	cout<<zhishu(abs(a[j]-a[i]),d)<<" "<<a[i]<<" "<<a[j]<<" "<<abs(a[j]-a[i])<<endl;
				if(abs(a[j]-a[i]-d)<d&&zhishu(abs(a[j]-a[i]),d)==true&&abs(a[j]-a[i])%d!=0)
				{
					//cout<<a[i]<<" "<<a[j]<<endl;
					ans++;
				}
			}
		}
	}
	cout<<ans<<endl;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		flag=1;
		cin>>n>>d;
		memset(a,0,sizeof(a));
		for(int i=1;i<=n;i++) 
		{
			cin>>a[i];
		}
		solve2();
	}
	return 0;
}
