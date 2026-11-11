#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int a[N];
int sum;
int ans;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	int l=1,r=1;
	while(r<=n)
	{
		while(r+1<=n&&sum<=m-(r-l+1)*(a[r+1]-a[r]))
		{
			sum+=(r-l+1)*(a[r+1]-a[r]);
			r++;
//			cout<<r<<" "<<l<<" "<<sum<<"\n";
		}
//		cout<<l<<" "<<r<<"\n";
		ans=max(r-l+1,ans);
		int k=(r-l+1)*(a[r+1]-a[r]);
//		cout<<";\n";
		if(r==n)
			break;
//		cout<<m-k<<" "<<sum-(a[r+1]-a[l]); 
		while(l+1<=r+1&&sum>m-k)
		{
			sum-=(a[r+1]-a[l]);
			l++;
//			cout<<r+1<<" "<<l<<" "<<sum+k<<"\n";
		}
//		cout<<"\n\n";
		sum+=k;
		r++;
//		cout<<l<<" "<<r<<"\n";
		ans=max(r-l+1,ans);
	}
	cout<<ans;
	return 0;
} 