#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=1e5+5;
int n,ans[N];
long long A[N],S[N],m;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int i,j,k,maxn=0;
	scanf("%d%lld",&n,&m);
	for (i=1;i<=n;i++) scanf("%lld",&A[i]);
	sort(A+1,A+n+1);
	for (i=1;i<=n;i++) S[i]=S[i-1]+A[i];
	for (i=1;i<=n;i++)
	{
		int l=1,r=i,mid;
		while (l<r)
		{
			mid=(l+r)/2;
			//printf("%d\n",A[i]*(i-mid+1)-(S[i]-S[mid-1]));
			if (A[i]*(i-mid+1)-(S[i]-S[mid-1])>m) l=mid+1;
			else r=mid;
		}
		ans[i]=(i-l+1);
	}
	for (i=1;i<=n;i++) maxn=max(maxn,ans[i]);
	printf("%d\n",maxn);
	return 0;
}
