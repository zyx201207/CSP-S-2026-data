#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long int n,m,a[N],b[N];
int ans=0;
int check(int l,int r)
{
	long long int t=a[r]*(r-l+1)-b[r]+b[l-1];
	if(t<=m)
	return 1;
	else
	return 0;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int i;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	
	for(i=1;i<=n;i++)
	b[i]=b[i-1]+a[i];
	
	int l=1,r=n,mid;
	for(i=1;i<=n;i++)
	{
		l=1,r=i;
		while(l<=r)
		{
			mid=l+r>>1;
			if(check(mid,i))
			{
				ans=max(ans,i-mid+1);
				if(mid==1)
				break;
				else
				r=mid-1;
			}
			else
			{
				l=mid+1;
			}
			
		}
	}
	cout<<ans;
	return 0;
}

