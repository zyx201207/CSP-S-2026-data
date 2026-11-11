#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
long long n;
long long m;
long long a[N];
long long h[N];
bool check(int l,int r)
{
	if(((r-l+1)*a[r]-(h[r]-h[l-1]))<=m) return true;
	return false;
}
bool cmp(int x,int y)
{
	return x<y;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	long long sum=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		
	}
	sort(a+1,a+n+1,cmp);
	//for(int i=1;i<=n;i++) cout<<a[i];
	for(int i=1;i<=n;i++){
		h[i]=h[i-1]+a[i];
	}
	long long ans=1;
	long long x=0;
	for(int i=2;i<=n;i++){
		int l=1,r=i;
		while(l<=r)
		{
			int mid=(l+r)>>1;
			if(check(mid,i))
			{
				r=mid-1;
			}
			else l=mid+1;
		}
		//cout<<l<<" "<<i<<endl;
		//cout<<check(l,i)<<endl;
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
}



