#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
struct st
{
	int sum;
	char c;
}a[N];

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,ans=0;cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i].sum>>a[i].c;
	int i=1,j=n;
	while(1)
	{
		if(a[i+1].sum==0)break;
		if(a[i].sum==0)i++;
		if(a[j].sum==0)j--;
		if(a[i].c==a[j].c)
		{
			int x=min(a[i].sum,a[j].sum);
			a[i].sum-=x;
			a[j].sum-=x;
		}
		else
		{
			int x=min(a[i].sum,a[j].sum);
			ans+=x;
			a[i].sum-=x;
			a[j].sum-=x;
		}
	}
	cout<<ans;
	return 0;
}
