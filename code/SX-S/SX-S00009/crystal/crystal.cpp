#include<bits/stdc++.h>
using namespace std;
int a[500005],c[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++)c[i]=a[i]-a[i-1];
	int l=1,r=0,sum=0,maxx=0;
	int ans=0;
	while(sum+c[r+1]*(r+1-l)<=m&&r<=n)
	{
		r++;
		ans++;
		sum+=c[r]*(r-l);
	}
	if(r>n)
	{
		cout<<n;
		return 0;
	}
	while(l<=r&&r<n)
	{
		cout<<l<<' '<<r<<endl;
		maxx=max(maxx,ans);
		r++;
		ans++;
		sum+=a[r]*(r-l);
		while(sum>m)
		{
			sum-=a[r]-a[l];
			l++;
			ans--;
		}
	}
	cout<<max(maxx,ans);
    return 0;
}
//5 8 -3 -1 2 2 7