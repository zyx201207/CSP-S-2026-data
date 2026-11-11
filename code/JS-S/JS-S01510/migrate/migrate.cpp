#include<bits/stdc++.h>
using namespace std;
#define ll long long
int c,t,n;
ll d;
ll x[2222222];
int dis[2222222];
int m[2222222];
int ans;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	if( c==11 or c==12)
	{
		for(;t;t--)
		{
			
			scanf("%d%lld",&n,&d);
			for(int i=1;i<=n;i++)
			{
				scanf("%lld",&x[i]);
			}
			ll rd=abs(x[2]-x[1]);
			int kn=2*(d/rd)-1;
			int ans=n-kn;
			//if(t==11)cout<<n<<' '<<d<<' '<<rd<<' '<<kn<<' '<<x[1]<<' '<<x[2]<<' '<<x[n]<<' ';
			if(kn<=1 or ans<0) printf("0\n");
			else printf("%d\n",ans);
		}
		return 0;
	}
	for(;t;t--)
	{
		//cout<<"t"<<t<<endl;
		ans=0;
		scanf("%d%lld",&n,&d);
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&x[i]);
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				dis[j]=999999999;
				m[d]=0;
			}
			dis[i]=0;
			for(int j=i;j<=n;j++)
			{
				
				int k=j+1;
				while(x[k]-x[j]<=d&&k<=n)
				{
					//cout<<k<<' '<<dis[k]<<endl;
					if(dis[k]>dis[j]+1)
					{
						dis[k]=dis[j]+1;
						m[k]=1;
					//cout<<j<<' '<<dis[j]<<' '<<k<<' '<<dis[k]<<endl;
					}
					else if(dis[k]==dis[j]+1)m[k]++;
					k++;
				}
			}
			for(int j=i;j<=n;j++)
			{
				//cout<<m[j]<<' ';
				if(m[j]==2)ans++;
			}
			//cout<<endl;
		}
		printf("%d\n",ans);
	}
	return 0;
}
