#include<stdio.h>
#include<set>
#include<unordered_map>
int w[500000];
std::unordered_map<int,int> s2line[500000];
long long dis[500][500];
std::set<int> line[500];
long long nearest(int r,int t)
{
	long long ans=1e18;
	for(std::pair<int,int>i:s2line[r])
	{
		for(std::pair<int,int>j:s2line[t])
		{
			ans=std::min(ans,i.second+j.second+dis[i.first][j.first]);
		}
	}
	return ans;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int n,m,q,i,j,k,r,t;
	scanf("%*d%d%d%*d%d",&n,&m,&q);
	for(i=0;i<m;++i)
	{
		scanf("%d",w+i);
	}
	for(i=0;i<n;++i)
	{
		scanf("%d",&k);
		for(j=0;j<k;++j)
		{
			scanf("%d%d",&r,&t);
			r--;
			s2line[r][i]=t;
			line[i].insert(r);
		}
	}
	for(i=0;i<n;++i)
	{
		for(j=0;j<n;++j)
		{
			dis[i][j]=1e18;
		}
		dis[i][i]=0;
	}
	for(i=0;i<n;++i)
	{
		for(int station:line[i])
		{
			for(std::pair<int,int> temp:s2line[station])
			{
				if(temp.first==i)
				{
					continue;
				}
				dis[temp.first][i]=dis[i][temp.first]=std::min(dis[i][temp.first],(long long)temp.second+s2line[station][i]);
			}
		}
	}
	for(i=0;i<n;++i)
	{
		for(j=0;j<n;++j)
		{
			for(k=0;k<n;++k)
			{
				if(dis[j][k]>dis[j][i]+dis[i][k])
				{
					dis[j][k]=dis[k][j]=dis[j][i]+dis[i][k];
				}
			}
		}
	}
	for(i=0;i<q;++i)
	{
		scanf("%d%d",&r,&t);
		r--;
		t--;
		printf("%lld\n",nearest(r,t)+r[w]+t[w]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
