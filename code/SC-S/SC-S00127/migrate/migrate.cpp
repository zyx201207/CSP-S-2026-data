#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=114514;
int a[20*N],b[20*N];
bool check(int x,int y,int d)
{
	int cnt=0;
	for(int i=x+1;i<y;i++) if(b[i]-b[x-1] <= d && b[y]-b[i-1] <= d) cnt++;
	if(cnt==2) return 1;
	else return 0;
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	scanf("%lld%lld",&c,&t);
	while(t--)
	{
		int n,d;
		scanf("%lld%lld",&n,&d);
		memset(b,0,sizeof b);
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
			b[i]=b[i-1]+a[i];
		}
		if(c<=2)
		{
			int ccnt=0;
			for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) if(b[j]-b[i-1]>d && check(i,j,d)) ccnt++;
			cout<<ccnt<<'\n';continue;
		}
		else puts("0");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}