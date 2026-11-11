#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#define LL long long
using namespace std;
const int MAXN=5e2+10,MAXM=5e5+10;
vector<int> v[MAXM]; 
vector<LL> t[MAXM];
LL dist[MAXN][MAXN];
LL n,m,q,d,w[MAXM];

void Floyd()
{
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
			}
		}
	}
}

LL red()
{
	LL ret=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')
	{
	 	ret*=10;
	 	ret+=ch-'0';
	 	ch=getchar();
	}
	return ret;
}

void wri(LL x)
{
	if(x>9)wri(x/10);
	putchar(x%10+'0');
}

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	//ios::sync_with_stdio(0);
	//cin.tie(0),cout.tie(0);
//	clock_t st=clock();
	memset(dist,0x3f,sizeof dist);
	int c;
	c=red();
	n=red();
	m=red();
	d=red();
	q=red();
	
	for(int i=1;i<=m;i++)w[i]=red();
	
	for(int i=1;i<=n;i++)
	{
		int k=red();
		for(int j=1;j<=k;j++)
		{
			int ind=red();
			LL w=red();
			v[ind].push_back(i);
			t[ind].push_back(w);
		}
	}
	
	for(int i=1;i<=n;i++)dist[i][i]=0;
	
	for(int i=1;i<=m;i++)
	{
		for(int j1=0;j1<v[i].size()-1;j1++)
		{
			for(int j2=j1+1;j2<v[i].size();j2++)
			{
				int x1=v[i][j1],x2=v[i][j2];
				LL len=t[i][j1]+t[i][j2];
				dist[x1][x2]=dist[x2][x1]=min(dist[x1][x2],len);
			}
		}
	}
	
	Floyd();
	
	for(int i=1;i<=q;i++)
	{
		LL ans=1e18;
		int x=red(),y=red();
		for(int j1=0;j1<v[x].size();j1++)
		{
			for(int j2=0;j2<v[y].size();j2++)
			{
				ans=min(ans,dist[v[x][j1]][v[y][j2]]+t[x][j1]+t[y][j2]);
			}
		}
		wri(ans+w[x]+w[y]),putchar('\n');
	}
//	clock_t ed=clock();
//	cerr<<(double)(ed-st)/ CLOCKS_PER_SEC<<'\n';
//	cerr<<w[201584]<<' '<<w[206120]<<' '<<dist[209][204]<<' '<<v[201584].size()<<'\n';
	return 0;
}
//T2 si lu zheng li miao
//hua yi ge xiao shi cai zhu yi dao di tie wu xiang miao
//ming ming yang li yi hen rong yi kan chu lai you xiang de hua 3 <-> 4 bu guan na ge fang xiang dou bu ke neng cheng li miao
//mao mao shi sha mao QAQ
//ba di tie xian lu shi wei jie dian miao
//pao Floyd miao
//bu dui miao
//zhe tu mei you fu quan miao
//dij jiu xing le miao
//zhe tu ke neng hen chou mi de gan jue miao
//kong pa hai shi Floyd miao
//deng xia wo zi ji ka ka shi shi ba miao
//ran hou lian ge di tie zhan ge zi pi pei di tie xian lu miao
//zui duo d^2 miao
//jian tu tong li miao
//yi ge zhan mei ju jin guo ta de liang tiao xian lu miao
//ye shi d^2 miao
//fu za du O(md^2+qd^2+n^3) miao
//zhu yi chang shu miao
//mei you duo ce mao mao yao kai xin de shang vector la miao

//yang li guo le miao
//ea da yang li si le miao
//xian rou yan tiao shi ba miao
//fan hui 0 shuo ming bu shi RE miao
//zuo fa ying gai ye jia bu liao miao
//zheng que xing wu xu zheng ming ba miao

//wen ti zhao dao le miao
//zhe zhi sha mao gei suo you shu zu quan yong le MAXN miao
//MAXM bei yi wang le miao
//zhe ju ran neng kang dao di liu zu shu ju miao
//qian mian de yang li dei you duo shui a miao
//er qie wei shen me fan hui 0 a miao
//xian zai da yang li quan guo miao!
//mao mao qie le liang dao ti le miao!
//yi xi dang nian bei T1 ka ku de ri zi miao!
//yi qu bu fu fan le miao!
//yang li zui da 0.3s miao
//ying gai gou le miao

//rou yan jian cha yi bo zai qu pian fen miao

//cha bu duo ba
//kai T3 pian fen miao
