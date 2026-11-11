#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
int c,T,n,d,a[N],arr[N],ans;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&T);
	while(T--)
	{
		memset(arr,0,sizeof arr);
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(a[j]-a[i]>d)
				{
					arr[i]=j-1;
					break;
				}
			}
			if(arr[i]==0) arr[i]=n;
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+2;j<=n;j++)
			{
				if(a[j]-a[j-1]>d) break;
				if(a[j]-a[i]<=d) continue;
				int f=0;
				int cnt=0,id=i;
				for(int k=i+1;k<j;k++)
				{
					if(a[k]-a[id]>d)
					{
						if(cnt>2)
						{
							f=3;
							break;
						}
						if(cnt==2)
						{
							f=1;
						}
						cnt=0;
						id=k-1;
					}
					if(arr[k]==arr[arr[id]]||arr[k]>=j) cnt++;
				}
				if(f==3) continue;
				if(cnt==2)
				{
					f=1;
				}
				if(cnt>2)
				{
					f=0;
				}
				if(f==1)
				{
					ans++;
				}
			}
		}
		printf("%lld\n",ans);
		ans=0;
	}
	return 0;
}
