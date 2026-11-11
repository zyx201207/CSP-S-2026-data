#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
int n,m,ans=0;
ll a[N];
ll sum=0;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int i=1,j=1;
	ll now=a[1];
	while(j<=n)
	{
		sum+=(a[j]-now)*(j-i);
//		cout<<i<<" "<<j<<" "<<sum<<'\n';
		while(sum>m&&i<j){
			sum-=(a[j]-a[i]);
			i++;
		}
		ans=max(ans,j-i+1);
//		cout<<i<<" "<<j<<" "<<sum<<" "<<ans<<'\n';
		now=a[j];
		j++;
	}
	cout<<ans;
	return 0;
}

