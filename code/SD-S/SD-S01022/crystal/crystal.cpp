#include<bits/stdc++.h>
using namespace std; 
const int N=500100;
int a[N],d[N];
int main()
{
 	freopen("crystal.in","r",stdin);
 	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	long long m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) d[i]=d[i-1]+a[i];
	int sum=INT_MIN;
	for(int i=1;i<=n;i++)
	{
		int l=i,r=n,mid,res=1;
		while(l<=r)
		{
			mid=(l+r)>>1;
			long long than=(1LL)*a[mid]*(mid-i+1)-d[mid];
			if(than<=m)
			{
				res=max(mid,res);
				l=mid+1;
			}
			else r=mid-1;	
		}
		int ans=res-i+1;
		sum=max(sum,ans);
	}
	cout<<sum;
	return 0;
}
