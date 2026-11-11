#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int a[N],n,m,sum,ma;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	sum=a[1]*2;
	for(int l=1,r=1;l<=n&&l<=r;l++)
	{
		if(l==1) sum-=a[l];
		else sum-=a[l-1];
		while(((a[r+1])*(r-l+1)-sum)<=m&&r<n) r++,sum+=a[r];
		ma=max(ma,r-l+1);
	}
	cout<<ma<<endl;
	return 0;
}
