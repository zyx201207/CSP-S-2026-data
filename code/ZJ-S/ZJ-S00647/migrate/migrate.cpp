#include <bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int c,t;
int n;
long long d;
long long x[N];
long long f[5005][5005];
int s[5005][5005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d %d",&c,&t);
	while(t--)
	{
		scanf("%d %lld",&n,&d);
		memset(f,0x7f,sizeof(f));
		memset(s,0,sizeof(s));
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&x[i]);
			if(x[i]-x[i-1]<=d) f[i-1][2]=1,s[i-1][2]=1;
			else f[i-1][2]=INT_MAX,s[i-1][2]=0;
		}
		long long ans=0;
		for(int len=3;len<=n;len++)
		{
			for(int l=1;l+len-1<=n;l++)
			{
				for(int i=l+1;i<=l+len-1-1;i++)
				{
					f[l][len]=min(f[l][len],f[l][i-l+1]+f[i][l+len-1-i+1]);
				}
				if(x[l+len-1]-x[l]<=d) 
				{
					f[l][len]=1,s[l][len]=1;
					continue;
				}
				for(int i=l+1;i<=l+len-1-1;i++)
				{
					if(f[l][len]==f[l][i-l+1]+f[i][l+len-1-i+1])
					{
						s[l][len]+=s[l][i-l+1]*s[i][l+len-1-i+1];
					}
				}
				//cout<<l<<' '<<l+len-1<<' '<<s[l][len]<<' '<<f[l][len]<<endl;
				if(s[l][len]==2) ans++;
			}
		}
		printf("%lld\n",ans);
	}
}