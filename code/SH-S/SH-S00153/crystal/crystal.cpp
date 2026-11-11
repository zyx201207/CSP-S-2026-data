#include<bits/stdc++.h>
using namespace std;
int N;
long long M,csl[500005];
bool check(int mid)//check(mid):能否达到mid颗水晶合成
{
	int i;
	long long sum=0,_min=LONG_LONG_MAX;
	for(i=1;i<=mid;++i)
		sum=sum+csl[mid]-csl[i];
	_min=min(_min,sum);
	for(i=2;i<=N-mid+1;++i)
	{
		sum=sum+(csl[i+mid-1]-csl[i+mid-2])*(mid-1)-(csl[i+mid-2]-csl[i]);
		_min=min(_min,sum);
	}
	return _min<=M;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int i,l=1,r,mid;
	scanf("%d %lld",&N,&M);
	r=N;
	for(i=1;i<=N;++i)
		scanf("%lld",&csl[i]);
	sort(csl+1,csl+1+N);
	while(l<=r)
	{
		mid=(l+r)>>1;
		if(check(mid))
			l=mid+1;
		else
			r=mid-1;
	}
	printf("%d",r);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
