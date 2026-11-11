#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,a[5000010],sum[5000010],ans=0,l=1,cha[5000010];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		if(i>1)
		{
			cha[i]=cha[i-1]+a[i]-a[i-1];	
		}
		sum[i]=sum[i-1]+(a[i]-a[i-1])*(i-l);
//		cout<<sum[i]<<endl;
		if(sum[i]<=m)
		{
			ans=max(ans,i-l+1);
		}
		else
		{
//			cout<<i<<endl;
//			cout<<cha[l]<<endl;
//			cout<<endl;
			while(sum[i]>m)
			{
				sum[i]-=(cha[i]-cha[l]);
				l++;
			}
//			cout<<sum[i]<<endl;
			ans=max(ans,i-l+1);
		}
	}
	cout<<ans<<endl;
	return 0;
}

