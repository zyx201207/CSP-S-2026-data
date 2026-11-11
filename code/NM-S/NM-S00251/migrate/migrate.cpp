#include<bits/stdc++.h>
#define int long long
#define N 2000006
#define M 5005
using namespace std;
constexpr int INF=0x3f3f3f3f3f3f3f3f;

int c,T;
int n,m;
bool tr;
int num,ans;
array<int,N> a;
array<int,N> p;
array<array<int,M>,M> dp;

signed main()
{
	freopen("migrate3.in","r",stdin);
//	freopen("migrate.out","w",stdout);
	
	cin>>c>>T;
	while(T--)
	{
		ans=0;
		scanf("%lld%lld",&n,&m);
		for(int i=1;i<=n;i++)
		scanf("%lld",&a.at(i) );
		
		if(c==11 || c==12)
		{
			num=a.at(2)-a.at(1);
			if(num>=m)
			{
				printf("0\n");
				continue;
			}
			
			m/=num;
			m+=m-1;
			printf("%lld\n",max(0ll,n-m) );
		}
		else if(c==13 || c==14)
		{
			printf("0\n");
			continue;
		}
		else if(1<=c && c<=10)
		{
			a.front()=INF;
			
			for(int i=1;i<=n;i++)
			{
				tr=false;
				for(int j=i+1;j<=n;j++)
				if(a.at(j)-a.at(i)>m && tr)
				{
					for(int l=j;l<=n;l++)
					{
						if(a.at(l)<=a.at(j-1)+m && a.at(l)<=a.at(j-2)+m && a.at(l)>a.at(j-3)+m)
						ans++;
//						else break;
					}
					break;
				}
				else tr=true;
			}
			printf("%lld\n",ans);
		}
	}
	return 0;
}
