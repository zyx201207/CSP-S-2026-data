#include<bits/stdc++.h>
using namespace std;
int n;
struct node
{
	long long sum;
	char s;
}a[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].sum>>a[i].s;
	}
	int l=1,r=n;
	long long ans=0;
	while(l<r)
	{
		
		if(a[l].s!=a[r].s)
		{
			int k=min(a[l].sum,a[r].sum);
			ans+=k;
			a[l].sum-=k,a[r].sum-=k;
			if(a[l].sum==0)l++;
			if(a[r].sum==0)r--;
		}
		if(a[l].s==a[r].s)
		{
			int k=min(a[l].sum,a[r].sum);
			a[l].sum-=k,a[r].sum-=k;
			if(a[l].sum==0)l++;
			if(a[r].sum==0)r--;
		}
	}
	cout<<ans;
	return 0;
}
