#include<bits/stdc++.h>
#define int long long
using namespace std;

int n,m,s,l,r,ans,cnt,mid,a[500001],z[500001];

int check(int now)
{
	cnt=0;
	l=1;
	r=now;
	while(l<=r)
	{
		mid=(l+r)/2;
		if(a[now]*(now-mid+1)-(z[now]-z[mid-1])<=m) r=mid-1;
		else l=mid+1;
	}
	return now-l+1;
}

signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;++i) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;++i) z[i]=z[i-1]+a[i];
    for(int i=1;i<=n;++i) ans=max(ans,check(i));
    cout<<ans;
    return 0;
}

/*

写在前面
1.请关注 cath20 喵~（全网同名，并非猫娘）
2.让我上一下迷惑行为打赏awa

-------华丽的分割线（【欢愉】版）------- 

正文（中英双语，但是乐子&垃圾翻译，沃的英语成绩虽然有 140 但是语法填空错一堆）

这也许是沃的最后一次 CSP 了吧
Maybe this is my own "one last dance(1)"

这让沃开始思考，沃是否是因为喜欢才学的 OI
This got me thinking whether I studied OI 'cause I love it

答案很明显，不是
Obviously, no

想必大家初学的时候都觉得 OI 十分简单，很喜欢学 OI 
I think all the oiers said "so easy" or "I like OI(2)" as beginners

但是现在都觉得很难很恶心
But now they say "f**k CCF" and "s**t"(3)

比如现在的沃更喜欢数学
For example, now I like MO more

但是在学习 OI 的这段时间里
But during my OI life

沃学到了不少知识
I learned a lot

也逃了不少课
And banned at least 4 whks every week  

还打了不少游戏、看了不少小说
Played lots of games, read lots of novels

老米的游戏有原神、崩铁、崩三、绝区零
The miHoYo ones are Genshin, Honkai:Star Rail, bh3, zzz

当然还有库洛的鸣潮
And mc made by Kuro Games

小说看过几本网文，但我更喜欢龙族和盗笔系列 
I read several shits, but I prefer Dragon Raja and 盗墓笔记

初中的时候，每周五的17：30就放学了
We left school at 17:30 on Fridays at junior high

但是我有一个朋友，他(4)要留下来等20：00高中生放学
But one of my friends stayed for the senior high students until 20:00

于是我们就留在教室里面边写作业边玩原神
So we stayed to play Genshin until 20:00(5) 

或者去打羽毛球
Or went to the playground to play goodminton(6)

周六或者假期的时候，沃中午就一个人在寝室看小说，或者和女孩子们玩耍
On Saturdays or holidays, I read novels alone or played with the others at noons

现在想来，真是一段美好的时光啊
So wonderful to play everyday

T1 是签到，T2 也可以暴力，也许沃会得到 S 1= 然后去 NOIP
Maybe I can get 100+ and go to NOIP

但我是走不到省队那一步的
But I can't take part in NOI

沃本来就是一个普通入
I'm an ordinary girl after all

也没有太多学 OI 的天赋 
And I have better talents in MO

沃已经知足了
I'm totally satisfied

正文部分太煽情了，根本不是沃的风格
Actually I'm SB today

沃的风格应该是：嘻~退役写什么文，快笑呀！
I should say: Hail Aha(7)

嗯，有道理，但是悲悼伶人也是【欢愉】的人呐
Bullshit, Aha does whatever she likes

反差怎么你了？
Acting is so interesting 

 
 
最后用《远航星の告别》和《昔涟》对 CSP 说再见吧 

远航星の告别

That snowflake once fell on my nose
Now flying backwards to last winter
I realize that hellos are goodbyes
The moment I softly let go off your hand

Winds hum through the trembling branches
A song for a soul bound to soar to the very edge of this starry ocean
Even if we're meant to fall apart
I will gaze at where you are for all time

Bon Voyage
May your path be clear
May you get to where dreams are all crystalline and sweet 
Please crack a little smile
You won't be alone
In this world you've chosen as your own

Don't worry
I'm well aware that all snowfalkes melt in the end
Which is sign of warmth and hope of spring
So I'll dance flamboyantly into that good night

Bon Voyage
May your path be clear
May you get to where dreams are all crystalline and sweet 
Please crack a little smile
You won't be alone
In this world you've chosen as your own

Timing is such a dazzling riddle
Guess I'll spend my whole life unraveling it
Though it might cost me everything I have
I never regret it wouldn't have it any other way cuz

Those who trace starlight on their lonely roads
Will find their destinations int the cosmos
Meeting you in that swirling snowfalls
The most beautiful thing ever happened to me


昔涟 Ripples of past Reverie

曾许下心愿 等待你 的出现
褪色的秋千 有本书 会纪念
我循着时间 捡起梦 的照片
童话还没有兑现 却需要说再见

如果有一天 岁月晕开书页
请把我模糊的字迹当作笑脸

很久前 想象 今天 画面
哭着 笑着 告别
陌生的情节 熟悉的侧脸 都重叠 oh~
出发前 无数 星光 缱倦
有回忆 落在 指尖
当时间向前 我会在原地 流连

当漪涟 一滴 一点 出现
轻轻 去向 天边
不管多遥远 都是追不上的思念 oh~
会不会 可能 还能 相见
再回头 只看一眼 

当漪涟 消散 万千 不见
永恒和瞬间 都被爱意成全
我的明天叫做昨天 oh~
要相信 浪漫 一如 初见
请笑着 向我 道别
最后这一页 就让它无言
我会在扉页 等待你续写 起点 



正文注释 
(1)one last dance：出自崩坏三的歌曲《TruE》，意为最后一舞，
                   也可理解为原神中“水神の最后一舞”
(2)I like OI：取自步步高词典笔
(3)"f**k CCF" and "s**t"：暴戾语言，作者自动和谐了 
(4)他：是的你没看错他就是一个男孩子，沃的朋友几乎都是男孩子，只有两个是女孩子 
(5)stayed to play Genshin：其实只在玩原神没有写作业
(6)goodminton：badminton太不吉利了（假），所以取反义词，令人忍俊不禁（大雾）
(7)本句中，"嘻~"出自诸神愚戏，英文来自"Hail Hi**er"，"Aha"是欢愉星神阿哈 
 


*/


















