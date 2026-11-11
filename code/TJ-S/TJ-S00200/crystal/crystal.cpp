#include<bits/stdc++.h>
using namespace std;
#define N 500005
#define int long long
int a[N],s[N];
int n,m;
int sum,ans;
void x()
{
	int t=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j>=1;j--)
		{
			sum+=a[i]-a[j];
			t++;
			if(sum>m)
			{
				t--;
				break;
			}
		}
		ans=max(ans,t);
		sum=0,t=0;
	}
	cout<<ans;
}
void y(int r)
{
	int t=0;
	for(int i=1;i<=n;i++)
	{
		sum+=i*r;
		t++;
		if(m<sum){break;}
	}
	cout<<t;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	bool flag=1;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	int r=a[2]-a[1];
	for(int i=2;i<=n;i++)if((a[i]-a[i-1])!=r)flag=0;
	if(flag) y(r);
	else x();
	return 0;
}
