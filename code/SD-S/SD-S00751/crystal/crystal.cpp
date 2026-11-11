#include<bits/stdc++.h>
using ll=long long;
using namespace std;
const int N=5e5+5;

int n;
ll m,a[N]; 

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	ll sum=0;int ans=0;
	for(int i=1,j=1;i<=n;i++)
	{
		sum+=a[i];
//		cout<<i<<" "<<j<<" "<<sum<<'\n';
		while(j!=i&&1ll*(i-j+1)*a[i]-sum>m) 
			sum-=a[j],j++;
		ans=max(ans,i-j+1);
	}
	cout<<ans<<'\n';
	return 0;
}
