#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int n,m;
int a[N],sum[N];
int mx=INT_MIN;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int r=1,l=0;
	sort(a+1,a+n+1);
	sum[1]=0;
	for(int i=2;i<=n;i++)
	{
		sum[i]=sum[i-1]+(i-1)*(a[i]-a[i-1]);
	}
	while(r<=n)
	{
		int x=sum[r]-sum[l]-(l-1)*(a[r]-a[l]);
		if(x>m)l++;
		else {
			mx=max(mx,r-l+1);
			r++;
		}
	}
	cout<<mx;
	return 0;
 } 
