#include<bits/stdc++.h>
#define pb emplace_back
//#define int long long
using namespace std;
const int N=5e5+10,M=3e5+10;
int n,m,a[N],ans[M],cnt[N],subB;
bool vis[M],subA=1;
vector<int> v;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<n;i++){
		if(a[i]>a[i+1]){
			subA=0;
		}
		if(a[i]!=a[i+1]){
			subB++;
		}
	}
	if(n<=500&&m<=200){
		for(int j=1;j<=n;j++){
			v.clear();
			for(int k=1;k<=m;k++){
				vis[k]=0;	
			}
			for(int k=j;k<=n;k++){
				if(vis[a[k]]){
					while(v.size()&&v.back()!=a[k]){
						vis[v.back()]=0;
						v.pop_back();
					}
				}else{
					v.pb(a[k]);
					vis[a[k]]=1;
				}
			}
			for(auto k:v){
//				cout<<k<<" ";
				ans[k]++;
			}
//			cout<<endl;
		}
		for(int i=1;i<=m;i++){
			cout<<ans[i]<<" ";
		}
		cout<<endl;
		return 0;
	}
	if(subA){
		int sum=0;
		for(int i=1;i<=n;i++){
			sum++;
			if(a[i]!=a[i+1]){
				cout<<sum<<" ";
			}
		}
		cout<<endl;
		return 0;
	}
	return 0;
}
/*
score 40 pts
time 93 min (although it was clearly wrong lol)
difficulty:4

all score: 100+100+100+40=340 pts
I hope I will keep my score at 340 pts

some samples:
4 3
1 2 1 3

10 3
3 1 2 1 3 2 3 1 2 1
I think I can't AK /ll/ll/ll
this problem now I only know the solution of O(mn^2)
I plan that in the last 15 min of this test,I will write something interesting here:)
at least I need 24 pts of mn^2 
24pts...all right,all right.
I think that T1<T3<T2<T4 is right/yes/yes/yes
think of special A.
notice that A:the infulence of take away some cards to answer is less or equal 1
and it is connect with count of this number.
OK I solved.
+16 pts,hooray
but I think that I must write my code right now.
btw,I found that I read the problem incorrectly.
I think about O(nm)
notice for every 1<=i<=m,1<=j<=n,because that every a card k is be taken away,there is a new card k be added in the list.
OK I solve O(mn^2)
OH I'm sb,that must be O(n(m+n)),but if I am hacked,it will be O(n(m+n^2)) /ll
OK let's write special A
a fun fact is that I notice that I even don't know when does the test end haha lol
I think maybe 12:00 :)
OK I found the solution of special A is a suffix sum through watching the big data yeah
OK I thought I have at least 40 pts now lol
think of special B
special B is equal to special A haha
Oh why it's wrong/ll/ll
ALright,I'm starting to write some interesting things here
so fun,right:)
OK it must be 12:00 ends
the last 15 min I'd like to rest for a moment lol
bye
The things I write is below,you see:

没错其实我会用中文而我前面一直不用是因为我只能看到我光标所在的那行文字（如果那行含有中文的话默认隐形，只有光标移动上去才能看得见），似乎是编辑器bug
OK 来直接耍起来

phigros update 7.8.0 《南亭的钥匙》 :
1.Xterfusion - t+pazolite & REDALiCE （请输入文本）
2.SuddeNDeath - xi & morimori （其实感觉这首还行，就是由于是高速钢琴作为主旋律，所以很难让人记忆深刻）
3.Speculation - ZAQUVA & 后面忘了
4.QQ - ZAQUVA & 后面忘了
5.Dream Away (feat.Yukacco) [Hylen Remix] - HARDCORE TANO*C （不能喷，这个是真南亭）
6.YUAGIRI - t+pazolite & DJ Myosuke （干嘛。。。）

你说得对，但是 Melodiniq 真的是神曲。
只有我觉得加长版没原版好听吗/yiw/yiw
你说得对，但是 Antigravity 真的是神曲。
由于我在某一场摸你赛写过这歌的曲评了所以我不写了哈哈。你们自己品鉴去吧，真的是神中神，tpz还是太伟大了/bx

Jumpscare in music game until 2026: 
RE:MASTER 15
AT 18
APPEND 38
MASSIVE 16+
Beyond 12

你说得对，但是 Only feels like nothing could be better when I'm with you when I'm with you ~

依旧打节奏，依旧全认识的这辈子有了：
X X XXX
XXX XXX XXXXXXX
X X XXX XX XX XXX XX
X X XX X X X X XXX X X XX X X X X XXX
XXXXX XXXXX XXXXX XXXXX
X X X XXXXX X X XXX X X XXXXX X X XXX

我士力架和德芙我都没吃/xk

额其实你在CSP中要少用auto，因为auto本质上是c++17的东西，评测机是c++14的，你用了有概率挂分
还有才注意到这场给的内存都是1024MiB/jy/jy/jy

爸爸别挂分爸爸别挂分爸爸别挂分爸爸别挂分爸爸别挂分爸爸别挂分爸爸别挂分爸爸别挂分爸爸别挂分爸爸别挂分爸爸别挂分爸爸别挂分爸爸别挂分爸爸别挂分爸爸别挂分
rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++

感觉我这次1=有了，感觉1=线上不了300的，这场比去年的T3T4简单了但是T2加强了不少
OK就这样吧，感觉灵感枯竭想不出啥了
祝自己的S rp++以及J不要挂分
*/
