#include<bits/stdc++.h>
using namespace std;
const int K=5e5+10;
long long n,m;
long long a[K],b[K];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
//	for(int i=1;i<=n;i++) cout<<a[i]<<" ";
//	cout<<"\n";
	for(int i=1;i<n;i++) b[i]=a[i+1]-a[i];
	long long l=0,r=0,ans=0;
	while(r<=n&&l<=n)
	{
		l++;
		m=m+a[r]-a[l-1];
		while(r<n&&m>=(r-l+1)*b[r])
		{
			r++;
			m=m-(r-l)*b[r-1];
		}
		ans=max(ans,r-l+1);
		if(r==n) break;
//		cout<<l<<" "<<r<<" "<<m<<" "<<ans<<"\n";
	}
	cout<<ans<<"\n";
	return 0;
}
