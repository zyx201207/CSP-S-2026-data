#include<bits/stdc++.h>
using namespace std;
const int Maxn=6e5+100;

long long n,m,a[Maxn],head=1,tail=1,ans;
long long sum;

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	while(head<=n)
	{
		sum+=a[head];
		while(tail<=head&&a[head]*(head-tail+1)-sum>m)
			sum-=a[tail],tail++;
		ans=max(ans,head-tail+1);
		head++;
	}
	cout<<ans;
	return 0;
}
