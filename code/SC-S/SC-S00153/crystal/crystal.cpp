#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+7;
int n,m,a[N],pref[N];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)pref[i]=pref[i-1]+a[i];
	int maxn=-1;
	for(int i=1;i<=n;i++)
	{
		int l=1,r=i;
		while(l<r)
		{
			int mid=(l+r)/2;
			if(pref[i]-pref[mid-1]>=a[i]*(i-mid+1)-m)r=mid;
			else l=mid+1;
		}
		//int k=lower_bound(pref+1,pref+1+i,pref[i]-a[i]*i+m)-pref;
		/*for(int j=i;j>=1;j--)
		{
			if(pref[i]-pref[j-1]>=a[i]*(i-j+1)-m)idx=j;
			//else break;
		}*/
		//cout<<idx<<"\n";
		maxn=max(i-l+1,maxn);
	}
	cout<<maxn;
	return 0;
}