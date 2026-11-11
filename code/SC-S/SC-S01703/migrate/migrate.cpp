#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
long long a[N];
int zy[N],kqy[N],zb[N],bd[N];
void read(long long &x)
{
	char c=getchar();
	x=0;
	bool f=0;
	while(c<'0' or c>'9')
	{
		if(c=='-')f=1;
		c=getchar();
	}
	while(c>='0' and c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	if(f)x=-x;
}
int main()
{
	freopen("migrate.in","r",stdin);//考试之后记得拿回水杯和纸巾
	freopen("migrate.out","w",stdout);//考试之后记得拿回水杯和纸巾
	int c,t;
	scanf("%d%d",&c,&t);
	while(t--)
	{
		//printf("t=%d\n",t);
		int n;
		long long d;
		scanf("%d%lld",&n,&d);
		for(int i=1;i<=n;i++)
		{
			read(a[i]);
		}
		if(n==1)
		{
			printf("0\n");
			continue;
		}
		if(c<=10)
		{
			for(int i=1;i<=n;i++)zy[i]=zb[i]=kqy[i]=0;
			for(int i=1;i<=n;i++)
			{
				for(int j=i;j<=n;j++)
				{
					if(a[j]-a[i]<=d)
					{
						zy[i]=j;
						if(!zb[j])zb[j]=i;
					}
				}
				if(zy[i]==zy[i-1])kqy[i]=kqy[i-1]+1;
			}
			int ans=0;
			for(int i=1;i<=n;i++)
			{
				int zh=0;
				for(int j=i;j!=n;j=zy[j])//遍历每个最优，看到下一个最优的空间中，有多少个是可以改变的
				{
					for(int k=j+1;k<=zy[j];k++)
					{
						int gh=zh+(j!=i?j-zb[k]:0);//这一步跳跃可以改的量，如果是第一步则无法更改
//						if(i==1 and j==3)
//						{
//							printf("i%d,j%d,k%d:gh%d,zh%d:zb[%d]=%d\n",i,j,k,gh,zh,k,zb[k]);
//						}
						if(gh==1)
						{
							//printf("%d->%d\n",i,k);
							ans++;
						}
					}
					if(j!=i)zh+=kqy[j];
					if(zy[j]==j)break;
				}
			}
			printf("%d\n",ans);
		}
		else if(c<=12)
		{
			long long cs=d/(a[2]-a[1]);
			if(cs>1)printf("%lld\n",max(0ll,n-cs*2+1));
			else printf("0\n");
		}
		else//等一会儿再写，分数不足以让我浪费这么多时间
		{
			for(int i=1;i<=n;i++)bd[i]=0;
			int l=1;
			for(int i=1;i<=n;i++)
			{
				while(a[i]-a[l]>d)l++;
				if(i-l>=2)
				{
					//printf("%d为r：bd[%d]++\n",i,l);
					bd[l]++;
				}
			}
			int r=1;
			long long ans=0;
			for(int i=1;i<=n;i++)
			{
				while(a[r+1]-a[i]<=d and r<n)r++;
				//printf("i=%d:r=%d\n",i,r);
				if(r-i>=2)
				{
					//printf("%d为l：bd[%d]=%d\n",i,r-1,bd[r-1]);
					ans+=bd[r-1];
				}
			}
			printf("%lld\n",ans);
		}
		
	}
	return 0;
}
/*
高分暴力肯定有少量思考，最短路线显然是贪心吧，那么最短路线唯二意思就是，路径上有且仅有一次迁徙，少走一个且仅能一个岛仍可达到目标
我们发现这个若前面的迁徙能够少走一个岛，那么后面的迁徙必须是刚好后一个能多走，否则后一次迁徙少走一个岛和这个方法是一样的效果。
每次先贪心找到最优路线，然后枚举所有的点，将点的权值赋值为最大前移个数（将这个岛屿能前移多少个保证仍可到达下一个），若路径上的和是1，则可以。
这个东西他要求路径，那么先建一个最优链，直接计算最后一个岛，其他岛是正常的移动链，查询即可。
这个不枚举还能怎么做？
只枚举一个开头，然后一直找下一个最优岛，考虑中途所有岛最大前移个数之和即可。
A性质：相当于一次迁徙长度固定，那么枚举所有可能出现的长度，数学方法即可判断了（显然，必须长度为2x-1的形式）
B性质：就是1与n最大距离2x，显然只能是2x长度的路线可以，并且长度也固定，设为a到b，中转处为c，那么a->c->b和a->c+1->b都要满足。
然后又因为其他的都不应该满足，所以算出最大的c，然后可以看出b最小能到多少，算出后显然可以
枚举每个a，然后显然只会有一个c是符合条件的，并且可以通过同样的方法确定b这边c应该怎么取。
*/
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

13 2
5 2
1 2 3 4 5
4 2
1 2 3 4

*/