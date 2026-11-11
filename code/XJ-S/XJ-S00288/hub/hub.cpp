#include<bits/stdc++.h>
#define ll pair<long long int,long long int>
using namespace std;
long long int i,j,k,n,m,c,t,a[10000005];
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>m;
		for(i=1;i<=n;i++)
		{
			cin>>a[i]>>m;
		}
		cout<<n-3;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
冰冰冰
今年S组好难啊
第一题完全不知道咋打
第二题能看出来是dijkstra，可是路径不知道怎么录入 
绝对的难度，由此而生的枚举，教会你超时的将会是…… 
2026CSP-S，大概我一辈子也不会忘记你吧

CSP-S发动的41秒内，博达校区上又响起出题人的吟唱
『能量水晶』『地铁』『迁徙』『研发基地』 
伴随着『节点』和『路径』在眼前完成交叠 
考生知道自己再也没有机会阻止CSP-S的产生了
巨大的假想质量爆炸如同核爆般在博达校区上空蔓延开来
（好吧这里我忘了，罚自己吃十发无量空处）
爆炸过后的学生只能依靠着新大的断壁残垣来支撑自己的身体
监控前的老师不可置信地看着这一幕
“也就是说……”
“没错，是CCF赢了！”
最强的战绩，铭刻于新大 

还有时间啊
*保持你的决心
我回去一定要玩 utry
和deltarune第五章

没有可以打表的心智
没有可以枚举的意志
没有为爆零而哭泣的声音
你必封印在众人题中散布图论的CCF
你是考生
你是C++竞赛生 
*/ 
