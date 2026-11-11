//这个题没有满足19，20约束的大样例吗 
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int n,m,a[N],s[N];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		int l=0,r=i-1,ans=i;
		while(l<=r)
		{
			int mid=(l+r)>>1;
			int suma=a[i]*(i-mid+1);
			int sumb=s[i]-s[mid-1];
			suma-=sumb;
			if(suma<=m) r=mid-1,ans=mid;
			else l=mid+1;
		}
		cnt=max(cnt,i-ans+1);
	}
	cout<<cnt;
	return 0;
}


