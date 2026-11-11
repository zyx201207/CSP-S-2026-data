#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long a[N];
queue<long long> q;
int main()
{
	freopen("crystal.in","r",stdin);//考试之后记得拿回水杯和纸巾
	freopen("crystal.out","w",stdout);//考试之后记得拿回水杯和纸巾
	int n;
	long long m;
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	long long hf=0;
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		hf+=(a[i]-a[i-1])*q.size();
		q.push(a[i]);
		while(hf>m)
		{
			hf-=a[i]-q.front();
			q.pop();
		}
		ans=max(ans,int(q.size()));
	}
	printf("%d\n",ans);
	return 0;
}
/*
对于一个值x，参与合成的水晶一定是更小的那一批。
我们考虑排序后对每个值（当然跳过不是水晶大小的值）维护参与合成的水晶，每次加入这些水晶，增加花费，然后pop掉不能加的水晶
*/