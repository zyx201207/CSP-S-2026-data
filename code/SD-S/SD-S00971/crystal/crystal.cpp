#include<bits/stdc++.h>
using namespace std;
long long n,l=1,ans=1,m,a[505005];
__int128 num;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++)
	{
		num+=(i-l)*(a[i]-a[i-1]);
		while(num>m)num-=a[i]-a[l],l++;
		ans=max(ans,i-l+1);
//		cerr<<num<<" "<<ans<<endl;
	}
	cout<<ans;
	return 0;
}

