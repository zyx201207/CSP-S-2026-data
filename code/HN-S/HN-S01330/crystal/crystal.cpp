#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[500005],sum,minn,minid1,minid2;
int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	while(1)
	{
		minn=1e9;
		//sort(a+1,a+n+1);
		for(int i=2;i<=n;i++)
		{
			if(minn>a[i]-a[i-1]&&a[i]-a[i-1]>0)
			{
				minn=a[i]-a[i-1];
				minid1=i-1;
				minid2=i;
			}
		}
		if(m-minn<0) break;
		cout<<minn<<'\n';
		m-=minn;
		a[minid1]+=minn;
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++) 
	{
		sum+=(a[i]==a[i-1]);
	}
	cout<<sum+1;
	return 0;
}
