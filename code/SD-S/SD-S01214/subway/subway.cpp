/*
Author:蝴蝶(lg uid 663638)
Start Coding: 14:52
Finish Coding: 15:07
Finish Debugging: 15:16 
*/
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int inf=0x071266ccff66ccffll;
int c,n,m,d,q,w[500005],ct[500005],id[500005][21],ti[500005][21],dis[502][502];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1,k;i<=n;i++)
	{
		for(int j=1;j<=n;j++)if(j!=i)dis[i][j]=inf;
		cin>>k;
		for(int j=1,a,t;j<=k;j++)
		{
			cin>>a>>t;ct[a]++;
			id[a][ct[a]]=i;
			ti[a][ct[a]]=t;
		}
	}
	for(int i=1;i<=m;i++)for(int j=1;j<=ct[i];j++)for(int k=1;k<=ct[i];k++)dis[id[i][j]][id[i][k]]=min(dis[id[i][j]][id[i][k]],ti[i][j]+ti[i][k]);
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)for(int k=1;k<=n;k++)dis[j][k]=min(dis[j][k],dis[j][i]+dis[i][k]);
	for(int i=1,u,v,ans;i<=q;i++)
	{
		ans=inf;cin>>u>>v;
		for(int j=1;j<=ct[u];j++)for(int k=1;k<=ct[v];k++)ans=min(ans,ti[u][j]+ti[v][k]+dis[id[u][j]][id[v][k]]);
		cout<<ans+w[u]+w[v]<<'\n';
	}
}
//bug: inf 不能太大，inf 设成 66ccff66ccff0712 会导致溢出。 

/*
若能向神灯许愿
我想整个世界
陷入一次 不被悲伤打扰的睡眠
温柔的月光 将实现我最渺小的 那个心愿
当一切还没改变

当你还不曾离开
火柴暖光摇曳
冬日的花于是也未因寒冷凋谢
趿着水晶鞋 我赶往空旷的宫殿
哪怕幻觉和痛觉在脚底相互粘连

复苏的回忆似堪堪破茧的蝶
举起她充血的双翼
在灰暗的人群中起舞盘旋
让我再看这绝美的风景一眼 就一眼
仿佛也能感染上些许鲜艳

童话只美在温柔却从不续写
当这世界再次苏醒
我便挥一挥石头与之告别
喧嚣照常将这细枝末节忽略
无人关心美好曾于斯沉淀

永眠中有童话里形容的一切
有你陪在我的身边
心甘情愿被纺锤扎破指尖
等我深爱的回来

我们经历的瞬间
那些鲜活笑面
删繁就简 被岁月压缩之后干瘪
委屈又求全 在梦中任他们重演
一遍一遍 直到我终于疲倦

大脑美化了一切
将岁月压缩成幻觉
与漫漫黑夜
你对我许下的誓言 是转瞬即逝的光源
于是蝴蝶才自愿被回忆压成书签

这是我最后一次将世界怀缅
解开被暂停的时间
所有滤镜和魔法消失不见
让我再看着定格的默片一遍 就一遍
然后将自由还给被困的蝶 

童话只美在温柔却从不续写
从现在起期待明天
明天故事会有全新的章节
新生的奇迹覆盖过页脚残缺
终会开满在这重生的花园

——《世界沉睡童话》 
*/ 
