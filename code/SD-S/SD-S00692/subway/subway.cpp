#include <bits/stdc++.h>
using namespace std;
const int N=505,M=500005;
int c,n,m,d,q,w[M];
struct node
{
	int k,p[M],t[M];
}a[N];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].k;
		for(int j=1;j<=a[i].k;j++)
			cin>>a[i].p[j]>>a[i].t[j];
	}
	for(int i=1;i<=q;i++)
	{
		int x,y;
		cin>>x>>y;
		cout<<w[x]+w[y]<<'\n';
	}
	return 0;
}
//别泄气，老伙计 
/*
自我介绍来啦，这次写的会比J组详细一点（好像也没详细多少） 
昵称：元耀mark（洛谷zyx0326) 
姓名：xxx
年龄：12
性别：男
学校：绿衣使者（什么玩意啊这是）拼音首字母与学校简称相同，具体哪个学校自己猜 
年级：初一
考点：山东外国语职业技术大学
爱好：打K牌（zyx03262025#4587）有兴趣的自己加
个人简介：一个喜欢打游戏的OIer 
*/ 
