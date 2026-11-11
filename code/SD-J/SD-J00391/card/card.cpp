/*
希望不要乱码 
was writen by ww3733a at 10:42 maybe AKed(have not checked) 
please use the ANSI to read it thank you so much
通过了T4的所有数据，但是数据只满足21,22而非23-25，写完之后还要检查一下 

感慨万千啊 最后一次csp-j 明年就高一了
我不知道难度如何 9:52 AC T1+T2
10:12 AC T3 10:42 AC T4 
此处的AC指的是通过所有样例而非100%获得100分

寄希望于下午的CSP-S了 加油 

吐槽一下这个FC.exe 不忽略行末空格，我一直以为自己错了，改了20分钟，不然你以为
if(i<m) cout<<' '; 是哪来的。 

在2024年，我第一次参加csp-j 并以240分的成绩获得了一等奖 这时候我还没有真正的学编程 
只看过几本书，比如啊哈算法 C++程序设计 真正的上课只是在国庆期间的一段集训 可谓非常幸运
直到2025年暑假，我到**某机构**学习编程，认识了朱老师(@ProtectEmmm /bxbxbx)，在他的带领下，
我系统学习了基础的知识，码风也是他教的。但是当时我报名了CSP-S，于是我就自己学习CSP-S算法，
途径有很多，比如买洛谷深入浅出，看视频，问ai，看题解之类，这也是我学习编程最热情的时候 
于是1st Nov 2025 我走上了赛场，经过了2.5个小时的奋战艰难切下了T1黄题，然后并在T2中获得了
64分，当时T2是蓝题（还没有青题），比分数线高13分，获得了一等奖。（j组就不这么理想了，
t2n,m写反100->35 当时还太弱不会t3 t4正解，235分获得了二等奖，不过不管怎么说我很满意，
我觉得我自己特别幸运，每次都正好想到了思路。）
于是到了NOIP2025 由于NOIP2025其实是NOIPlus 2025 我就得了112分遗憾离场
此后，我又把OI放下了。。。。。。。（途中有一次市赛，我用了规定的一半时间就给AK了。。） 
然后到了2026年的暑假 我忽然意识到OI的重要性，于是“稍微”更加努力地开始学OI，
在闫老师(/bx luogu @Smash_，有下划线)的带领下，我学习了一些比较高级的算法。
那么就到了现在了，能AK J组我是没想到的，总之感谢老师的教学吧。

在文化课方面，自招也马上到来了，数理化的学习也让我每天晚上没有时间去学编程了，意识到编程
的重要性后，却再也没有时间了，初二下学期我有一大把的时间，全都用在了玩florr.io上，
这玩意真是误人子弟，现在想玩也没时间了，少壮不努力，老大徒伤悲说的没毛病啊。 

最喜欢的科目就是化学了，至少目前是，希望以后能成为一个化学研究者，不过确实生命危险有点大
不过为了科学真理愿意献出生命，倒是希望不要像之前制F2那么危险的工作。 

最好的科目可能是物理吧，虽然初三上学期啥都看不出来。

感谢以上提到的老师（朱老师和闫老师），以及我们的数学，物理，化学老师，和认真敬业的班主任
感谢所有教过我的老师，和互帮互助的同学们，我不知道他们让不让我写真名，所以我就不写了。 
希望jjc（同校oier也是最好的朋友）能稳住csp-s 一等奖，希望zyb和lbr能过自招。
希望自己能ak j组并在s组获得200分，也希望自己能过自招。  

至于为什么在j组写，一个是因为j组有剩余时间，s组可能没时间了，另一个是j组似乎ak了很开心。

到这里已经11:09了，去对拍了。 

luogu/CF/AT ww3733a florr.io ww3733a lv143 30+s 
邮箱 ww333xyz@outlook.com QQ 3835139116

-----ww3733a
	31st Oct 2026
	
11:41补：
T3我拍出来了一个答案为0的数据:
12 10
539614365 687226841 959157254 420240100 824121920 153465267 309216412 336276222 674637105 214256458 20532227 20629048  
*/

/*
force写太慢了好像拍不起来。
算一下复杂度吧，但我不会算。
ok我明白了，这样的话我每次sol(x)跳到sol(nxt[x]+1)就消掉了一个颜色，那么最多执行m次消颜色
那就是O(nm)? 好像过不了，不对，感性分析一下我觉得不可能吃满O(nm)，就这样吧。 
*/

/*
force.cpp
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll=long long;
#define rint FastRead()
#define wint FastWrite

int FastRead() {
	int ans=0,sgn=0,ch=getchar();
	while(ch==' '||ch=='+'||ch=='\n'||ch=='\r') ch=getchar();
	if(ch=='-') sgn=1,ch=getchar();
	while(ch>='0'&&ch<='9') ans=(ans<<1)+(ans<<3)+(ch^48),ch=getchar();
	return sgn?-ans:ans;
}
void FastWrite(int x) {
	if(x<0) x=-x,putchar('-');
	if(x>9) wint(x/10);
	putchar(x%10+'0');
}

const int N=5e5+10;
const int M=3e5+10;

int timer,pos[M],ans[M],ondesk[N],a[N];
bool tmp[M];

void Solve() {
	int n,m; cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int k=1;k<=n;k++) {
		for(int i=1;i<=timer;i++) ondesk[i]=0;
		for(int i=1;i<=m;i++) tmp[i]=0,pos[i]=0;
		timer=0;
		for(int i=k;i<=n;i++) {
			if(pos[a[i]] && ondesk[pos[a[i]]]==a[i]) {
				for(int j=pos[a[i]]+1;j<=timer;j++)
					ondesk[j]=0;
				timer=pos[a[i]];
			} else {
				ondesk[++timer]=a[i];
				pos[a[i]]=timer;
			}
		}
		for(int i=1;i<=timer;i++) {
			if(ondesk[i]) tmp[ondesk[i]]=1;
		}
		for(int i=1;i<=m;i++) ans[i]+=tmp[i];
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
}

int main() {
	freopen("card3.in","r",stdin);
	freopen("card.out","w",stdout);
	cin.tie(0),cout.tie(0);
	ios::sync_with_stdio(0);

	Solve();
	return 0;
}
*/
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll=long long;
#define rint FastRead()
#define wint FastWrite

int FastRead() {
	int ans=0,sgn=0,ch=getchar();
	while(ch==' '||ch=='+'||ch=='\n'||ch=='\r') ch=getchar();
	if(ch=='-') sgn=1,ch=getchar();
	while(ch>='0'&&ch<='9') ans=(ans<<1)+(ans<<3)+(ch^48),ch=getchar();
	return sgn?-ans:ans;
}
void FastWrite(int x) {
	if(x<0) x=-x,putchar('-');
	if(x>9) wint(x/10);
	putchar(x%10+'0');
}

const int N=5e5+10;
const int M=3e5+10;

int ans[M],a[N],nxt[N],ww3733a[M],tmp[M];
int n,m;

void sol(int x,int timer) {
	if(x>n) return ;
	if(nxt[x]) x=nxt[x];
	if(tmp[a[x]]!=timer) ans[a[x]]++,tmp[a[x]]=timer;
	sol(x+1,timer);
}

void Solve() {
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=n;i>=1;i--) {
		if(!ww3733a[a[i]]) ww3733a[a[i]]=i;
		nxt[i]=ww3733a[a[i]];
	}
	for(int k=1;k<=n;k++) {
		sol(k,k);
	}
	for(int i=1;i<=m;i++) {
		cout<<ans[i];
		if(i<m) cout<<' ';
	}
}

int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin.tie(0),cout.tie(0);
	ios::sync_with_stdio(0);

	Solve();
	return 0;
}

