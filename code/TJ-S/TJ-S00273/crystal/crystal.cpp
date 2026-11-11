#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500010];
int main() 
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int c=abs(a[2]-a[1]);
	if(a[1]+c*(n-1)==a[n]) 
	{
		int cnt=c,j=1,ans=1;
		while(cnt<=m) 
		{
			ans++;
			j++;
			cnt+=j*c;
		}
		cout<<ans;
		return 0;
	}
	else 
	{
		int num=-9999999;
		for(int i=2;i<=n;i++)
		{
			int ans=1;
			int cnt=0;
			for(int j=i-1;j>=1;j--)
			{
				cnt+=abs(a[j]-a[i]);
				if(cnt<=m)
				{
					ans++;
				}
			}
			num=max(num,ans);
		}
		cout<<num;
	}
	return 0;
}
