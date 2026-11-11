#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5,M=1e5+5;
int n,m;
long long A[N],ans;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int C,T;
	scanf("%d%d",&C,&T);
	while (T--)
	{
		ans=0;	
		int i,j,k;
		long long d,cnt,sum;
		scanf("%d%lld",&n,&d);
		for (i=1;i<=n;i++) scanf("%lld",&A[i]);
		for (i=1;i<=n-3;i++)
		{
			if (A[i+3]-A[i]>d&&A[i+3]-A[i+1]<=d&&A[i+2]-A[i]<=d)
			{
				cnt=0;sum=1;
				for (j=i;j>=1&&A[i+2]-A[j]<=d;j--) cnt++;
				sum*=cnt;
				cnt=0;
				for (j=i+3;j<=n&&A[j]-A[i+1]<=d;j++) cnt++;
				sum*=cnt;
				ans+=sum;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}

