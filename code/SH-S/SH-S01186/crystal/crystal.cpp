#include<bits/stdc++.h> 
using namespace std;
long long n,m;
long long a[500005];
long long ans;
int main()
{
	int i,head,tail;
	long long cost;
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for(i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	a[0]=a[1];
	head=1;
	tail=1;
	cost=0;
	ans=-1;
	while(head<=n)
	{
		cost+=(head-tail)*(a[head]-a[head-1]);
		while(a[head+1]==a[head] && head<n)
		{
			head++;
		}
		while(cost>m)
		{
			cost-=(a[head]-a[tail]);
			tail++;
		}
		if(head-tail+1>ans) ans=head-tail+1;
		head++;
	}
	cout<<ans;
}
