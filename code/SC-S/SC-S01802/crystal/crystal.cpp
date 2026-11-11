#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N=5e5+10;
typedef long long ll;
ll m,sum,ans,n,a[N];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(ll l=1,r=1,len;r<=n;r++){
		sum+=a[r],len=r-l+1;
		while(l<=r&&a[r]*len-sum>m)sum-=a[l++],--len;
		ans=max(ans,len);
	}
	cout<<ans;
	return 0;
}