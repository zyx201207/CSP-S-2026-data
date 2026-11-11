#include<iostream>
#include<cstdio>
#define LL long long
using namespace std;
const LL MAXN=2e6+10,INF=1e18+10;
LL dist[MAXN],cnt[MAXN],pos[MAXN];
LL n,d,t,ans;

LL red()
{
	LL ret=0,opt=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')opt=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
	 	ret*=10;
	 	ret+=ch-'0';
	 	ch=getchar();
	}
	return ret*opt;
}

void wri(LL x)
{
	if(x>9)wri(x/10);
	putchar(x%10+'0');
}

void solve()
{
	n=red(),d=red();
	for(int i=1;i<=n;i++)pos[i]=red();
	ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)dist[j]=INF;
		dist[i]=0;
		for(int j=i;j<=n;j++)
		{
			for(int k=j+1;k<=n&&pos[k]-pos[j]<=d;k++)
			{
				dist[k]=min(dist[k],dist[j]+1);
			}
		}
		
		for(int j=i;j<=n;j++)cnt[j]=0;
		cnt[i]=1;
		for(int j=i;j<=n;j++)
		{
			for(int k=j+1;k<=n&&pos[k]-pos[j]<=d;k++)
			{
				if(dist[k]==dist[j]+1)cnt[k]+=cnt[j];
				cnt[k]=min(cnt[k],3ll);
			}
		}
		
		for(int j=i;j<=n;j++)
		{
			if(cnt[j]==2)ans++;
		}
	}
	wri(ans),putchar('\n');
}

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	//ios::sync_with_stdio(0);
	//cin.tie(0),cout.tie(0);
	int c=red();
	t=red();
	while(t--)solve();	
	return 0;
}
//mao mao you yi zhong zui huai O(n^3) de zuo fa miao

//deng xia T1 shi bu shi ke yi shuang zhi zhen miao
//suan le you dian ma fan bu gai le miao
//wo jiu bu xing mou san zi mu zu zhi (ni xing wo shi SCP) de ce ping ji pao bu dong O(n log n) de 5e5 miao

//sheng ban ge xiao shi miao
//jian cha miao
//T4 pian bu dong miao
// $E[pts]=224$

//mao mao feng quan da jia shang ce suo yi ding yao ti qian bao miao
//bu yao kuai bie bu zhu le cai bao miao
//pai dui pai hao jiu miao
