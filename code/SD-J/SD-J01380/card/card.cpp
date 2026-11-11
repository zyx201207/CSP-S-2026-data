#include<bits/stdc++.h>
using namespace std;

/*稻香 周杰伦
对这个世界 你如果有太多的抱怨
跌倒了就不愿在走下去 为什么 人要这么的脆弱堕落
请你打开电视看看多少人 为生命再努力的走下去 我们是不是该知足
珍惜一切就算没有拥有
还记得你说家是唯一的城堡 随着稻香河流继续奔跑 
微微笑 小时候的梦我知道 
不要哭 让萤火虫带着你逃跑乡间的歌谣永远的依靠
回家吧回到最初的美好。
不要这么就想飘 就是向我说的 
追不了的梦换一个梦不久得了
给自己的记忆鲜艳上色 先把爱涂成喜欢的颜色
笑一个吧功成名就不是目的 让自己快乐快乐才是意义 
童年的纸飞机 今天终于飞回我手里
所谓那快乐 赤脚在稻田追蜻蜓追到累了 
偷吃水果被蜜蜂给盯到 怕了 谁在偷笑呢
我靠着稻草人 唱着歌 吹着风 睡着了 欧欧
 
*/ 
/*就是爱你 陶喆
欸哎~欧欧~诶诶~dan da da den da den da
我 一直都想给你说 你想给我的快乐
像宇宙给了沙漠
说 你会永远陪着我 作我的根和翅膀
让我飞 也会有回去的窝
偶我愿意 我也可以 失去一切来保护你
偶在一起 是个记叙的事 请记住我们相爱的方式 偶~欧欧
就是爱你爱着你 不管一路有多少风雨
就是爱你爱着你 放在你手心 那种感觉就是你 
*/ 
/*挪威的森林 伍佰
让我将你心儿摘下 试着将它慢慢融化 
看我在你心中是否仍完美无暇
你说真心总是可以解脱 真爱总是可以长久
为何你的眼里总有无不时的落寞 
是否我只是你一种寄托 真爱如何才能长久
心中那片森林何时才由我停留
哪里湖面总是澄清 哪里空气充满宁静
雪白明月照在大地 藏着你不愿提及的回忆 
应该是我不该问 让你平静的心再起涟漪
也许爱你的心超出了界限 我想拥有你所有的一切
应该是我不该问 不该让你再将往事重提
只是心中枷锁该如何才能解脱 
*/ 
/*伤心太平洋 任贤齐
离开真的残酷吗 或者温柔才是可耻的
或者孤独的人无所谓 无日无夜无条件
往前一步是黄昏 往后一步是人生 
风不平浪不静心还不安稳一座岛锁住一个人
我等的船还不来
我等的人他还不明白
寂寞沉沉往事沉入海未来不在我还在
如果潮去心也去 如果潮来你还不来
浮浮沉沉往事浮上来回忆回来你已不在
一波还未平息一波早就过去
茫茫人海狂风暴雨
一波还未平息一波早就过去
一生一世如梦初醒 藏在太平洋的深深伤心 
*/
/*海阔天空 beyond
今天我 寒夜里看雪飘过
怀着冷却的心窝赴远方
风雨里追赶雾里分不清影踪
天空海阔你与我可会变（谁没在变）
多少次迎着冷眼与嘲笑
从没有放弃过心中的理想
一霎那彷徨若有所思的感觉
不知不觉已看淡心里爱（谁明白我）
原谅我这一生放纵不羁爱自由
也会怕有一天会跌倒
背弃了理想谁人都可以 那会怕有一天只你共我
[超好听间奏] 
今天我 寒夜里看雪飘过
怀着冷却的心窝赴远方
风雨里追赶雾里分不清影踪
天空海阔你与我可会变（谁没在变）
原谅我这一生放纵不羁爱自由
也会怕有一天会跌倒
背弃了理想谁人都可以 那会怕有一天只你共我~欧耶！
原谅我这一生放纵不羁爱自由
也会怕有一天会跌倒
背弃了理想谁人都可以 那会怕有一天只你共我
*/
const int N = 5e5 + 5;
int n,m,a[N],b[N],c[N],f[N],fa[N];
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n;i ++) scanf("%d",&a[i]),f[i] = 1;
	for(int i = n;i >= 1;i --) {
		if(!c[a[i]]) {
			c[a[i]] = i;
			fa[i] = i + 1; 
			continue;
		}
		fa[i] = c[a[i]] + 1;
	}
	for(int i = 1;i <= n;i ++) {
		f[fa[i]] += f[i];
		b[a[i]] += f[i];
	}
	for(int i = 1;i <= m;i ++) printf("%d,",b[i]);
	return 0;
}
/*
Hello! 
My name is DF_G(luogu),I have no CSP-J/S before today 
Today is a sunny day
The code is so wonderful that I passed all the problem
I'm very excited!
but,I can believe my code because I think it's wrong
T1 is a easy problem.
T2 too. but maybe no people will fast think it was a  Manacher
   I think I'm so unsmart,the brain is in a deepsleep
T3 too.I don't know why zhe CCF make the easy problem in -J
   but I will thank CCF because I maybe can AK CSP-J
   I'm Just Grade 7,it's a magic to me.
   Can I make that?I think no.
T4 It's a hard problem!but maybe we can let a f means the id of i
   's color paint how many.well,we can know a i can pop all
   the value in [i+1,c[a[i]]，c means the color a[i] last disappear
   on the id c,so we can get fa[i] = c[a[i]] + 1 
   so f[i] = f[i] + f[fa[i]]，I did that!
   It means,if there is no questions I will AK CSP-J!
   I hope CSP-S in the afternoon will make a beautiful grade too.

At last,I hope everyone who watch that will AK NOIP!
I know,I don't do well in English.It will have many wrongs in it
if you make the dashang,please help me insert it.You can only copy 
it to show to everyone,it's OK too.

I think if Mx2013(his luogu name,his really name is mengningyu) 
Join this Match,he will get a good grade too!
but he only join the CSP-S. I don't Know why
Oh,there is over 1h I can play.I will go back to check my code,bye! 
*/
 
