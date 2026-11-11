#include<bits/stdc++.h>
#define int long long
#define lowbit(x) (x&(-x))
using namespace std;
int n,a[500005],sum[500005],ans,m;
map<int,int>mp;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i],mp[a[i]]++;
	sort(a+1,a+n+1,greater<int>());
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;i++)
	{
		int j=i;
		while(j<=n&&a[i]==a[j]) j++;
//		cout<<a[i]<<" "<<i<<" "<<j<<"\n";
		int l=j,r=n,pos=j-1;
		while(l<=r)
		{
			int mid=(l+r)>>1;
			int len=mid-j+1,w=sum[mid]-sum[j-1];
			if(a[i]*len-w<=m) l=mid+1,pos=mid;
			else r=mid-1;
		}
//		cout<<a[i]<<" "<<i<<" "<<pos<<"\n";
		ans=max(ans,pos-i+1);
//		if(ans==3) cout<<a[i]<<"\n";
		i=j-1;
	}
	cout<<ans;
	return 0;
}
//5 5
//1 2 4 8 9
//5 8
//-3 -1 2 2 7
