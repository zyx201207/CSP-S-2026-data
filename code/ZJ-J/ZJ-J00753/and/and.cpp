#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int a[N][30],b[N],n,k,v[N];
bool cmp(int x,int y)
{
	return x>y;
}
int xrt(int a,int b)
{
	int res=1;
	for(int i=1;i<=b;i++)
		res*=2;
	return res;
}
signed main()
{
 	freopen("and.in","r",stdin);
 	freopen("and.out","w",stdout);
 	ios::sync_with_stdio(0);
 	cin.tie(0);
 	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>b[i];
	sort(b+1,b+1+n,cmp);
	for(int i=1;i<=n;i++)
	{
		int x=b[i],cnt=0;
		while(x)
		{
			a[i][cnt]=x%2;
			x/=2;
			cnt++;
		}
	}
	int aqpc=k,ans=0;
	int x=b[k],cntt=0;
	while(x)
	{
		x/=2;
		cntt++;
	}
	ans+=xrt(2,cntt-1);
	while(b[aqpc+1]>xrt(2,cntt-1))
	{
		aqpc++;
	}
	for(int i=cntt-2;i>=0;i--)
	{
		int cnt=0;
		for(int j=1;j<=aqpc;j++)
			cnt+=a[j][i]*(1-v[j]);
		if(cnt>=k)
		{
			ans+=xrt(2,i);
			for(int j=1;j<=aqpc;j++)
				if(!a[j][i])
					v[j]=1;
		}
	}
	cout<<ans;
 	return 0;
}
