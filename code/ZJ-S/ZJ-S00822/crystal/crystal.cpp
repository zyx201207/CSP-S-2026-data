#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500500],cha[500500],sum[500500],ans;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++)
		cha[i]=a[i]-a[i-1],sum[i]=sum[i-1]+cha[i];
		int xx=0,s=m;
	for(int i=n;i>=1;i--)
	{
		if(i<=ans)
			break;
		s=s-xx+sum[i+1]-sum[i-ans+2]-cha[i-ans+2]+cha[i+1]*ans;
		if(s>=0)
			xx=m-s;
		while(s>0&&i-ans>0)
		{
			ans++;
			if(s>=sum[i]-sum[i-ans+1])
			{
				s-=sum[i]-sum[i-ans+1];
				xx+=sum[i]-sum[i-ans+1];
			}
			else
			{
				ans--;
				break;
			}
			
		}
	}
	cout<<ans;
}