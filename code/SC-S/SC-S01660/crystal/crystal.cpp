#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
long long a[500010];
long long b[500010];
int f(int x)
{
	
	int l=1,r=x,mid;
	while(l<=r)
	{
		mid=(l+r)/2;
		long long cha=b[x]-b[mid]-(mid-1)*(a[x]-a[mid]);
		if(cha==m)
		{
			cout<<cha<<' '<<x-mid+1<<endl; 
			return x-mid+1;
		}
		else if(cha>m)
		{
			l=mid+1;
		}
		else if(cha<m&&b[x]-b[mid-1]-(mid-1-1)*(a[x]-a[mid-1])>m)
		{
			return x-mid+1;
		}
		else 
		{
			r=mid;
		}
	}
	return x-r+1;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	a[0]=a[1];
	sort(a+1,a+n+1);
	b[1]=0;
	for(int i=2;i<=n;i++) b[i]=b[i-1]+(i-1)*(a[i]-a[i-1]);
	for(int i=1;i<=n;i++)
	{
		if(b[i]<=m) ans=max(ans,i);
		else
		{
			ans=max(ans,f(i)); 
		} 
		
	}
	cout<<ans;
	return 0;
 } 