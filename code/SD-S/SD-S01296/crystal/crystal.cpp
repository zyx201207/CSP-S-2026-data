#include <algorithm>
#include <iostream>
#define N 500005
#define int long long
using namespace std;
int a[N];
signed main()
{
	cin.tie(0);ios::sync_with_stdio(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int i,j,k,n,m;
	cin>>n>>m;
	for (i=1;i<=n;i++)  cin>>a[i];
	sort(a+1,a+n+1);
	j=1;int ans=1,tmp=0;
	for (i=2;i<=n;i++){
		tmp+=(a[i]-a[i-1])*(i-j);
		while (j<=i&&tmp>m)  tmp-=a[i]-a[j],j++;
		ans=max(ans,i-j+1);
	}
	cout<<ans;
	return 0;
}
