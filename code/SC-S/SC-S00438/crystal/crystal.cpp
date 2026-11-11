#include<bits/stdc++.h>
#define int long long
#define ex exit(0)
#define sinzo return
#define code 0
using namespace std;
const int N=2e6+10;
int a[N],b[N],c[N];
int n,m,k,ans,cnt,sum,mx=-1e18,mn=1e18;
bool check(int l,int r)
{
	int t=b[r];
	t-=b[l];
	t-=(a[r]-a[l])*(l-1);
	if(t<=m)return 1;
	else return 0;
	
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++)
	{
		sum+=(a[i]-a[i-1])*(i-1);
		b[i]=sum;
	}
	sum=0;
	
	for(int i=3;i<=n;i++)
	{
		int l=1,r=i;
		while(l<=r)
		{
			int mid=l+r>>1;
			if(check(mid,i))
			{
				r=mid-1;
			}
			else l=mid+1;
		}
		for(int j=max(l-2,1ll);j<=min(r+2,i);j++)
		{
			if(check(j,i))
			{
				ans=max(ans,(i-j+1));
				break;
			}
		}
	}
	cout<<ans;
	
	sinzo code;
}
/*
5 5
1 2 4 8 9

*/