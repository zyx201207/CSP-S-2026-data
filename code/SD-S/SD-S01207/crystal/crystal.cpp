#include<bits/stdc++.h>
#define int long long
#define endl '\n'
//#define p(x) cerr<<"debug:"<<__LINE__<<" "<<#x<<"="<<x<<endl;
using namespace std;
/*====================*/
const int N=5e5+10;
/*====================*/
int n,m;
int sum[N],a[N];
/*====================*/
bool check(int now,int W)
{
	int k=sum[now]-sum[now-W];
	k=a[now]*W-k;
	return k<=m;
}
/*====================*/
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>n>>m;
	sum[0]=0;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)sum[i]=a[i]+sum[i-1];
	int ans1=0;
	for(int i=1;i<=n;i++)
	{
		int l=1,r=i,ans=-1;
		while(l<=r)
		{
			int mid=(l+r)/2;
			if(check(i,mid))
			{
				ans=mid;
				l=mid+1;
			}
			else r=mid-1;
		}
		ans1=max(ans,ans1);
//		p(i);
//		p(ans1);
	}
	cout<<ans1<<endl;
	return 0;
}

