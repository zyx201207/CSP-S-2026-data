#include<bits/stdc++.h>
using namespace std;
unsigned long long c,n,m,d,q;
int main()
{
//目前，将线路作为点看待
//共用vector
//第一个点的编号=n+1最后一个点就是n+m+1
//ran er zhi neng guo 5haodian
//5haodian5miaotle houmiandebendiyunxinghuibeng(duxie?)
//xiangshangHNmihuoxingwei 
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
// zhuyidaot2yangli2chuxian325
	cin.tie(0);
	cout.tie(0);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	long long crz[m+100];
	for(long long int i=1;i<=m;i++)
	{
		scanf("%lld",&crz[i]);
	}
	vector<pair<long long int,long long int> > bian[n+m+100];
	for(long long int i=1;i<=n;i++)
	{
		long long l;
		scanf("%lld",&l);
		for(long long int j=1;j<=l;j++)
		{
			pair<long long int,long long int> l1,l2;
			scanf("%lld%lld",&l1.first,&l1.second);
			l1.first+=n;
			l2.second=l1.second;
			l2.first=i;
			bian[i].push_back(l1);
			bian[l1.first].push_back(l2);
		}
	}
	long long l1,l2;
	for(long long int i=1;i<=q;i++)
	{
		scanf("%lld%lld",&l1,&l2);
		l1+=n;
		l2+=n;
		long long dis[n+m+100];
		for(long long int i=1;i<=n+m+50;i++)
		{
			dis[i]=1000000001;
		}
		dis[l1]=-1;
		long long poi=l1;
		long long ans=1000000001;
		queue<pair<long long int,long long int> > qu;
		qu.push({l1,0});
		while(!qu.empty())
		{
			if(qu.front().first==l2)
			{
				ans=min(ans,qu.front().second);
				qu.pop();
				continue;
			}
			for(long long int j=0;j<bian[qu.front().first].size();j++)
			{
				if(qu.front().second+bian[qu.front().first][j].second<dis[bian[qu.front().first][j].first])
				{
//					printf("%lld %lld\n",bian[qu.front().first][j].first,qu.front().second+bian[qu.front().first][j].second); 
					qu.push({bian[qu.front().first][j].first,qu.front().second+bian[qu.front().first][j].second});
					dis[bian[qu.front().first][j].first]=qu.front().second+bian[qu.front().first][j].second;
				}
			}			
			qu.pop();
		 } 
		 printf("%lld\n",ans+crz[l1-n]+crz[l2-n]);
	}
//	for(long long int i=1;i<=n+m;i++)
//	{
//		printf("!\n");
//		for(long long int j=0;j<bian[i].size();j++)
//		{
//			
//			printf("%lld %lld\n",bian[i][j].first,bian[i][j].second);
//		}
//	}
//zuihou woqianhoubiying(zhuyaoshi in ing,en,eng)bufen
	return 0;
}
