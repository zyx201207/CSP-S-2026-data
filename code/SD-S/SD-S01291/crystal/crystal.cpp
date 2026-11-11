#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+7;
int n,m,res,ans;
int a[N],d[N],s[N];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++)
	{
		d[i]=a[i+1]-a[i];
		s[i]=s[i-1]+d[i];
	}
	ans=0;
	int l=1,r=1,res=0,len=1;
	while(l<=r&&r<=n)
	{
		res+=len*d[r];
		r++;
		if(r>n)	break;
		len=r-l+1;
		while(res>m)
		{
			len--;
			res-=a[r]-a[l];
			l++;
		}
		ans=max(ans,len);
	}
	cout<<ans;
	return 0;
}

