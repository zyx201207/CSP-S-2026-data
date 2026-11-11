
#include<bits/stdc++.h>
using namespace std;//É¾µôfreopenµÄ×¢ÊÍ£¡£¡£¡ 
long long n,cnt,i=1,m;
int ans;
int a[200010];


int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
    	scanf("%lld",&a[i]);
    	
	}
    
    //dfs(1,1);
    if(m==1)
	{
		for(int i=1;i<=n;i++)
		ans=max(ans,a[i]); 
		printf("%lld",ans);
		return 0;
	}
    else if(m==2)
    {
    	for(int i=1;i<=n;i++)
    	{
    		for(int j=i+1;j<=n;j++)
    		{
    			ans=max(ans,int(a[i]&a[j]));
    			
			}
		}
		printf("%lld",ans);
		return 0;
	}
	if(m==n)
	{
		ans=a[1];
		for(int i=2;i<=n;i++)
		ans&=a[i];
		printf("%lld",ans);
		return 0;
	}
	if(m=n-1)
	{
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(j==i) continue;
				ans&=a[i];
			}
		
		cnt=max(cnt,ans);	
		}
		printf("%d",cnt);
		return 0;
	}
	return 0;

}
