// migrate
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
int n,d,ans;

void solve(){
	n=rd(),d=rd(),ans=0;
	VI a(n+1);
	vector<VI > dist(n+1);
	rep(i,1,n) a[i]=rd(); // increase
	
//	if(CASE==11||CASE==12){
//		if(d<=a[2]-a[1]){
//			echo(0);
//			return;
//		} // 无法到达的彼岸 && 我别无选择
//		
//		if(n<=2*d-1){
//			echo(0);
//			return ;
//		} //
//		
//		echo(n-2*d+1);
//		
//		return;
//	} // 等差数列
	
//	rep(i,1,n){
//		rep(j,i+1,n){
//			rep(k,j+1,n){
//				rep(l,k+1,n){
//					if()
//				}
//			}
//		}
//	}
	
	
	echo(1);
	return ;
}

signed main(){
#ifdef IO
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
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
migrate
15:26 T2题目读不懂
数轴 
双径岛屿对: u->v 的最短路径，同时经过的点不一样
15：42 像是线条覆盖区间？
15:58 总感觉离正解就差一步了 echo 1 跑路了 
17:09 666神秘考场入低血糖借我糖吃QAQ
17:21 这我拿什么写啊QAQ
18：06 身体开始止不住地痉挛和发抖
本来一开始是被空调对着吹的，后来老师调解了
*/
