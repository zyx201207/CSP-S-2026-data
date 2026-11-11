#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
const int INF=9e12;
int n,m;
int a[N];
unordered_map<int,int>las;
priority_queue<int>pq;
int ans;

signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+1+n);

	int l=1,r=0;
	int mx=-INF,sum=0;

	for(int i=1;i<=n;i++)
	{
		if(!las[a[i]]||las[a[i]]<l)pq.push(a[i]);
		las[a[i]]=i;
		if(a[i]>mx)
			sum+=(r-l+1)*(a[i]-mx),
			mx=a[i];
		else sum+=(mx-a[i]);
		r=i;
		while(sum>m&&l<=r)
		{
			sum-=(mx-a[l]),l++;
			while(!pq.empty()&&las[pq.top()]<l)pq.pop();
			if(pq.top()<mx)
				sum-=(r-l+1)*(mx-pq.top()),
				mx=pq.top();
			//if(sum<=m)break;
		}
		ans=max(ans,r-l+1);
	}
	printf("%lld\n",ans);
	return 0;
}
