#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[500005];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	 } 
	 sort(a+1,a+1+n);
	int l=1,r=1;
	int cost=0;
	int maxlong=0;
	for(;r<=n;)
	{
		if(cost>m&&l<=r)
		{
			cost-=a[r]-a[l];
			l++;
		}else
		{
			r++;
			cost+=(a[r]-a[r-1])*(r-l);
			if(cost<=m)maxlong=max(maxlong,r-l+1);
		}
	}
	cout<<maxlong;
	return 0;
}
