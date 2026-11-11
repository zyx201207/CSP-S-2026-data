// crystal
#include<bits/stdc++.h>

#define int long long
#define db double
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
mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());

const int N=500005;
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

int n,m,ans=1ll;
int a[N];
db time1,time2;
int calc(int tmp,int m){
	int res=0;
	rep(i,1,n){
		if(a[i]==tmp){
			res++;
			continue;
		} 
		if(a[i]>tmp) break;
		if(m>=tmp-a[i]){
			m-=(tmp-a[i]);
			res++;
		}
	}
	return res;
}

void solve(){
	n=rd(),m=rd();
	rep(i,1,n) a[i]=rd();
	
	sort(a+1,a+n+1);
	
//	rep(i,1,n){
//		echo(a[i]," \n"[i==n]);
//	}
	if(n<=5000){
		rep(i,2,n){
			int tmp=calc(a[i],m);
			umax(ans,tmp);
		}
		echo(ans);
		return;
	}
	
	
	while(true){
		time2=clock();
		if(time2-time1>=950) break;
		int pos=(rnd()%n)+1;
		int tmp=calc(a[pos],m);
		umax(ans,tmp);
	}
	
	echo(ans);
	
	return ;
}

signed main(){
#ifdef IO
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
#endif
	time1=clock();
	int CASE=1;
//	CASE=rd();
	while(CASE--) solve();
#ifdef IO
	fflush(stdout);
	fclose(stdin);
	fclose(stdout);
#endif
	return 0;
}
/*
crystal

14:43 最多进行 m 次操作，将数列中相等的值最多
15:01 按照基准点，定一个数，取差值最小
15:06 假
15:19 写了个 n2，45pts 先过了
16:10 感觉可以参考模拟退火，但是我考场不敢打QAQ
16：12 算了，有何不敢/fn 考场发明模拟退火
16:34 tmd随机数忘记怎么写了（
空悲切啊！！！
16：45 严肃翻源文件找到，但是并无软用（
16:54 打了一个诡异的东西，理论可以AC，全看人品（（（
*/
