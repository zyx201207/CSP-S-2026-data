#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+5;
int a[N],s[N];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	bool f=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]==i)f=1;
		else 
		{
			f=0;
			break;
		}
	}
	if(f==1)
	{
		int cnt=2,res=1,j=1;
		while(res<=m)
		{
			j++;
			res+=cnt;
			cnt++;
		}
		cout<<j;
		return 0;
	}
	sort(a+1,a+1+n);
	bool flag=0;
	for(int i=2;i<=n;i++)s[i]=a[i]-a[i-1];
	for(int i=3;i<=n;i++)
	{
		if(s[i]==s[i-1])flag=1;
		else
		{
			flag=0;
			break;
		}
	}
	if(flag==1)
	{
		int cha=s[2];
		int cnt=cha,res=a[1],j=1;
		while(res<=m)
		{
			j++;
			res+=cnt;
			cnt+=cha;
		}
		cout<<j;
		return 0;
	}
	int mini=0;
	for(int i=1;i<=n;i++)
	{
		int ans=0;
		for(int j=1;j<i;j++)ans+=a[i]-a[j];
		if(ans<=m)mini=i;
		else if(ans>m)
		{
			cout<<mini;
			return 0;
		}
	}
	cout<<mini;
	return 0;
}
