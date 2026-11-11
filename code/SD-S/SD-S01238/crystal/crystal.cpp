#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int a[N],cf[N],qz[N];
int n,m,ans=1;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	stable_sort(a+1,a+n+1); 
	for(int i=2;i<=n;i++) cf[i]=a[i]-a[i-1];
	for(int i=2;i<=n;i++) qz[i]=qz[i-1]+cf[i];
	int l=1,r=2,s=cf[2],len;
	while(r<=n)
	{
		while(s>m&&l<=r) s-=qz[r]-qz[l],l++;
		ans=max(ans,r-l+1);
		r++;
		len=r-l;
		s+=cf[r]*len;
	}
	cout<<ans;
	return 0;
}
