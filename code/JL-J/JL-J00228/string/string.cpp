#include <bits/stdc++.h>
#define int long long
using namespace std;
char s[200005][3];
int a[200005];
char t[100000005];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	scanf("%lld",&n);
	int sum = 0;
	int maxx = 0;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld%s",&a[i],s[i]+1);
		sum+=a[i];
		maxx = max(maxx,a[i]);
	}
	if(n*maxx<=1e8)
	{
		int cnt = 0;
		for(int i=1;i<=n;i++)
		{
			int qwq = a[i];
			for(int j=1;j<=a[i];j++) t[++cnt] = s[i][1];
		}
		int anss = 0;
		for(int i=1;i<=cnt/2;i++)
			if(t[i]!=t[cnt-i+1]) 
					anss++;
		printf("%lld\n",anss);
	}
	else
	{
		int len = sum/2;
		int nowidxl = 0,nowidxr = 0;
		int ans = sum/2;
		int l = 0,r = n+1;
		char nowcl = '_',nowcr = '_';
		while(true)
		{
			if(nowidxl<=nowidxr)
			{
				l++;
				nowcl = s[l][1];
				nowidxl += a[l];
			}
			if(nowidxl>len) nowidxl = len;
			if(nowidxr>len) nowidxr = len;
			if(nowcl==nowcr)
			{
				ans-=min(nowidxl,nowidxr)-max(nowidxl-a[l],nowidxr-a[r]);
			}
			if(nowidxl>=len&&nowidxr>=len) break;
			if(nowidxr<=nowidxl)
			{
				r--;
				nowcr = s[r][1];
				nowidxr += a[r];
			}
			if(nowidxl>len) nowidxl = len;
			if(nowidxr>len) nowidxr = len;
			if(nowcl==nowcr)
			{
				ans-=min(nowidxl,nowidxr)-max(nowidxl-a[l],nowidxr-a[r]);
			}
			if(nowidxl>=len&&nowidxr>=len) break;
		}
		printf("%lld\n",ans);
	}

}//64