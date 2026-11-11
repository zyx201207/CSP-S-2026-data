#include<bits/stdc++.h>
using namespace std;
#define N 500005
long long n,m,a[N],wz,ks,js;
#define M 300005
bool flag[M+1];
long long cnt[M+1],qyg[M+1];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(long long i=0;i<n;i++)scanf("%lld",&a[i]);
	for(long long i=0;i<n;i++)
	{
		for(long long k=1;k<=m;k++)
		flag[k]=false;
		stack<long long>q;
		for(long long j=i;j<n;j++)
		{
			if(flag[a[j]])
			{
				while(q.top()!=a[j]){
					flag[q.top()]=false;
					q.pop();
				}
				q.pop();
			}
			q.push(a[j]);
			flag[a[j]]=true;
		}
		while(!q.empty())
		{
			cnt[q.top()]++;
			q.pop();
		}
	}
	printf("%lld",cnt[1]);
	for(long long j=2;j<=m;j++)
	{
		printf(" %lld",cnt[j]);
	}
	cout<<'\n';
	return 0;
}
