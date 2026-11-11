#include<stdio.h>
#include<algorithm>
long long a[500001];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m;
	scanf("%d %lld",&n,&m);
	for(int i=0;i<n;i++)
		scanf("%lld",&a[i]);
	std::sort(a,a+n);
	int head=0,tail=1,cost=0,answer=1;
	while(tail<n)
	{
		cost=cost+(a[tail]-a[tail-1])*(tail-head);
		while(cost>m)
		{
			cost=cost-(a[tail]-a[head]);
			head++;
		}
		tail++;
		answer=std::max(answer,tail-head);
	}
	printf("%d",answer);
	return 0;
}
