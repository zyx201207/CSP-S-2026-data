#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[500005],check[500005],x,y;//check检查当前站点是否被访问过 
struct station
{
	long long num[25],time[25],now;
}stt[500005];//num代表每个站点通过的地铁编号,time代表每个站点站厅到相应编号的地铁站台所需时间,now是当前存储的项目个数 
long long find(long long x1,long long y1)
{
	check[x1]=1;
	for (int i=1;i<=stt[x1].now;i++)
	{
		for (int j=1;j<=stt[y1].now;j++)
		{
			if(stt[x1].num[i]==stt[y1].num[j])
			{
				return stt[x1].time[i]+stt[y1].time[j];
			}
		}
	}
	long long mintime=2026103116330000,minnum;
	for (long long i=1;i<=m;i++)
	{
		if (check[i]==1||i==x1)
	    {
	    	continue;
	    }
	    for (int k=1;k<=stt[x1].now;k++)
	    {
	    	for (int j=1;j<=stt[i].now;j++)
	    	{
	    		if(stt[x1].num[k]==stt[i].num[j])
	    		{
	    			long long qqq=find(i,y1);
	    			if(qqq==-1) continue;
					if(stt[x1].time[k]+stt[i].time[j]+qqq<mintime)
					{
						mintime=stt[x1].time[k]+stt[i].time[j]+qqq;
						minnum=i;
					}
	    		}
	    	}
    	}
	}//i循环下一站点；k循环本站点地铁；j循环下一站点的地铁 
	check[x1]=0;
	if(mintime==2026103116330000) return -1;
	return mintime;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for (int i=1;i<=m;i++)
	{
		scanf("%lld",&w[i]);
	}
	for (long long i=1;i<=n;i++)
	{
	    long long kk;
		scanf("%lld",&kk);
		for (long long j=1;j<=kk;j++)
		{
			long long xx1,xx2;
			scanf("%lld%lld",&xx1,&xx2);
			stt[xx1].num[stt[xx1].now+1]=i;
			stt[xx1].time[stt[xx1].now+1]=xx2;
			stt[xx1].now++;
		}
	}
	for (long long i=1;i<=q;i++)
	{
		for (long long i=1;i<=m;i++)
		{
			check[i]=0;
		}
		scanf("%lld%lld",&x,&y);
		//cout<<find(x,y)<<endl;
		//cout<<w[x]<<" "<<w[y]<<endl;
		cout<<find(x,y)+w[x]+w[y]<<endl;
		//printf("%lld\n",find(x,y)+w[x]+w[y]);
	}
	return 0;
}

