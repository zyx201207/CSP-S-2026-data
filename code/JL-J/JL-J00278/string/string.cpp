#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,len=0,ans=0,len2=0;
int cnt[200005],f[200005];
char s[5];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld%s",&cnt[i],s);
		for(int j=1;j<=cnt[i];j++)
		{
			f[len+j]=(s[0]-'a'+1);
		}
		len+=cnt[i];
	}
	for(int i=1;i<=(len+1)/2;i++)
	{
		if(f[i]!=f[len-i+1])
		{
			ans++;
		}
	}
	printf("%lld",ans);
	return 0;
}