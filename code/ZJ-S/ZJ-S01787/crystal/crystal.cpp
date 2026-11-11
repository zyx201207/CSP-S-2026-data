#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int n,s[N],sum[N],m;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>s[i];
	sort(s+1,s+n+1);
	for(int i=2;i<=n;i++) s[i]-=s[1];
	s[1]=0;
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+s[i];
	int l=1,r=1,res=1,k=0;
	for(int i=2;i<=n;i++)
	{
		k+=(s[i]-s[i-1])*(r-l+1);
		r++;
		while(k>m&&l<r) k-=s[i]-s[l],l++;
		res=max(res,r-l+1);
	}
	cout<<res;
	return 0;
}

