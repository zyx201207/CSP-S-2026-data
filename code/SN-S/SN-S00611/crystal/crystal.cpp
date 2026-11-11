//SN-S00611
//¶­¹ú¶°
#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
long long l,r,ene,sum,ans;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n;
	cin>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<n;i++)
		a[i]=a[i+1]-a[i];
	l=r=1;
	while(r<n)
	{
//		cout<<l<<' '<<r<<' '<<ene<<' '<<sum<<endl;
		if(ene<=m)
		{
			ans=max(ans,(r-l+1));
			ene+=(r-l+1)*a[r];
			sum+=a[r];
			r++;
		}
		else
		{
			ene-=sum;
			sum-=a[l];
			l++;
		}
	}
	cout<<ans;
	return 0;
}
