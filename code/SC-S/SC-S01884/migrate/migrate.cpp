#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
int c,t,a;
long long x[2000005];
struct node{
	int y,dis;
	bool operator<(const node &B)const{
		return dis<B.dis;
	}
};
vector<int>v[5008];
int f1[5005][5005],f2[5005][5005],f3[5005][5005];
void dij(int x)
{
	priority_queue<node>q;
	q.push({x,0});
	while(!q.empty())
	{
		auto[y,dis]=q.top();
		q.pop();
		if(dis>f3[x][y])continue;
		for(auto ny:v[y])
		{
			int d=dis+1;
			if(d<f3[x][ny])
			{
				if(d<f2[x][ny])
				{
					if(d<f1[x][ny])
					{
						f3[x][ny]=f2[x][ny];
						f2[x][ny]=f1[x][ny];
						f1[x][ny]=d;
						q.push({ny,d});
						
					}
					else{
						f3[x][ny]=f2[x][ny];
						f2[x][ny]=d;
						q.push({ny,d});
					}
				}
				else{
					f3[x][ny]=d;
					q.push({ny,d});
				}
			}
		}
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c==11||c==12)
	{
		while(t--)
		{
			int n;
			long long d;
			scanf("%d%lld",&n,&d);
			
			for(int i=1;i<=n;i++)
				{
					scanf("%lld",&x[i]);
					
				}
			
			long long g=x[2]-x[1];
			long long gx=d/g;
			if(gx==0||gx==1||gx>n/2)
			{
				printf("0\n");
			}
			else{
				printf("%lld\n",n-2*gx+1);
			}
		}
		return 0;
	}
	if(c<=10)
	{
		while(t--)
		{
			int n;
			memset(f1,0x3f,sizeof(f1));
			memset(f2,0x3f,sizeof(f2));
			memset(f3,0x3f,sizeof(f3));
			long long d;
			scanf("%d%lld",&n,&d);
			scanf("%lld",&x[1]);
			for(int i=1;i<=n;i++)v[i].clear();
			long long now=1;
			for(int i=2;i<=n;i++)
			{
				scanf("%lld",&x[i]);
				while(x[i]-x[now]>d)now++;
				for(int j=now;j<i;j++)
				{
					v[i].push_back(j);
					v[j].push_back(i);
				}
				dij(i);
			}
			int ans=0;
			for(int i=1;i<=n;i++)
			{
				for(int j=i+1;j<=n;j++)
				{
					if(f1[j][i]==f2[j][i]&&f1[j][i]!=f3[j][i]&&f3[j][i]<=n)ans++;
				}
			}
			cout<<ans<<"\n";
		}
		return 0;
	}
	else{
		while(t--)
		{
			scanf("0\n");
		}
	}
	return 0;
}