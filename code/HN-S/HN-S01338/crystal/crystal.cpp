#include<bits/stdc++.h>
using namespace std;
const long long N=5e5+5;
int n,ans;
long long m;
long long a[N],r[N];
queue<long long>U;
set<long long>D;
int check(long long h)
{
	int mi;
	for(int i=1;i<=n;i++)
	{
		r[i]=h-a[i];
		if(r[i]==0)
		{
			mi=i;
		}
	}
	int use=0;
	long long sum=0;
	for(int i=mi;i>=1;i--)
	{
		if(sum+r[i]>m)
		{
			break;
		}
		else
		{
			sum+=r[i];
			use++;
		}
	}
	return use;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		if(D.find(a[i])==D.end())
		{
			D.insert(a[i]);
			U.push(a[i]);
		}
	}
	sort(a+1,a+n+1);
	long long h;
	while(!U.empty())
	{
		h=U.front();
		U.pop();
		ans=max(ans,check(h));
	}
	printf("%d",ans);
	return 0;
} 
