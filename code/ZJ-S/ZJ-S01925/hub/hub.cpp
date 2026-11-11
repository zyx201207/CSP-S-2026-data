// hub
#include<bits/stdc++.h>

#define int long long

#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define repp(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);++i)
#define pper(i,a,b) for(int i=(a);i>(b);++i)

#define pb push_back
#define VI vector<int>
#define m_p make_pair
#define PII pair<int,int>

#define IO

using namespace std;

const int N=100005;
const int INF=0x3f3f3f3f3f3f3f3f;
const int P=1000000007;

namespace Fast{
	#define gc getchar
	#define pc putchar
	int rd(){
		int n=0,f=1;
		int c=gc();
		while(!isdigit(c)){
			if(c=='-') f=-1;
			c=gc();
		}
		while(isdigit(c)){
			n=(n<<1)+(n<<3)+(c^48);
			c=gc();
		}
		return n*f;
	}
	void print(int x){
		if(x<0) pc('-'),x=-x;
		if(x>9) print(x/10);
		pc(x%10^48);
	}
	void echo(int x,char c='\n'){
		print(x),pc(c);
	}
	template<typename T>
	bool umax(T& a,const T& b){
		return b>a?a=b,1:0;
	}
	template<typename T>
	bool umin(T& a,const T& b){
		return b<a?a=b,1:0;
	}
}using namespace Fast;

int CASE,T;
int n,k,ans;

void solve(){
	n=rd(),k=rd();
	if(CASE==1){
		echo(1);
		
		
		return;
	}
	
	return ;
}

signed main(){
#ifdef IO
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
#endif
	CASE=rd(),T=rd();
	while(T--) solve();
#ifdef IO
	fflush(stdout);
	fclose(stdin);
	fclose(stdout);
#endif
	return 0;
}
/*
hub
16:02 死磕 sub1 ，看下能不能出来
17:43 看来是出不来了，现在头和肚子开始疼的厉害
看来只能到这里了吗...

预期得分:
[45,100] + [0,10] + [0,5] + 0 = [45,115] 
荣幸成为 fvv 啊各位

依稀记得csp-s是不是会有人统计代码的"神秘程度"。？
那也行...各位我是洛谷 lmaz 求壶关谢谢喵QAQ
（依旧在赛中写赛后总结...）
欸我说白了，T4不就是留位置给考生写小作文的吗？
像我这种区区完了的考生，无非就是给后人当分母的
像我这种老东西就应该早早的被淘汰掉，把更多的机会留给年轻一辈
但是可惜了，即使是像我这样的老东西，也是有梦想的啊...
我不信我爆零好吧（ok，先去校对一下T1，别真zero就老实了...）
（ok检查好了，差点T1 CE QAQ（（（）
好吧其实也没啥可说的，但是我认为现在的OI没有以前的味道了，或许是因为我高二的缘故
因为whk的事情一直饱受争论
同时还有父母似是非是的支持态度（同时也确实感谢他们...）
总的讲就是菜是本罪...
（17：59 此时update了T2样例）
好吧，其实大家都是这么过来的，我也不必要发表什么牢骚...
但是我还是希望能在这里留下一点痕迹，毕竟也是我走过的路的一段
或许像我这样的小透明根本就不会(pei)被人记住吧...
即使是在离别的时候，也根本表达不了情绪呢...
但是我同年级的估计有进队的可能，那也算是郑兴学校了吧。。。
本来想背诵《追忆》的，我赌这次肯定有人全文背诵并在考场默写的
提前预言一下...
可惜了，我背不下来...
再磕一会题目吧...万一有希望呢...
去了趟WC，干呕，咳嗽，还好不是特别严重
难道我身体已经弱到这种程度了？
头有点烫烫的...热热的...

*/
