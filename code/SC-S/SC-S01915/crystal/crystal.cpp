#include<bits/stdc++.h>
#define int long long
using namespace std;

const int M=5e5+10;
int n,m,a[M],s[M];
int ans;
int t;

bool check(int mid,int r)
{
	int l=r-mid+1;
	if(mid*t<=s[r]-s[l-1]+m) return true;
	return false;
}

signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		s[i]=s[i-1]+a[i];
	
	for(int i=1;i<=n;i++)
	{
		t=a[i];
		int ll=1,rr=i,mid;
		while(ll<rr)
		{
			mid=(ll+rr+1)/2;
			if(check(mid,i)) ll=mid;
			else           rr=mid-1;
//			cout<<"T: "<<ll<<" "<<rr<<endl;
		}
//		cout<<"A: "<<i<<" "<<ll<<" "<<t<<" "<<check(ll,i)<<endl;
		ans=max(ans,ll);
	}
	
	cout<<ans;
	
	return 0;
}