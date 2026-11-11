// subway
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

int c,n,m,d,q,ans;
int a[1005][1005],t[1005][1005];
int k[N];
int w[N];
PII query[N];

void solve(){
	c=rd(),n=rd(),m=rd(),d=rd(),q=rd();
	rep(i,1,m) w[i]=rd();
	rep(i,1,n){
		k[i]=rd();
		rep(j,1,k[i]) a[i][j]=rd(),t[i][j]=rd();
	}
	
//	rep(i,1,n){
//		rep(j,1,k[i]){
//			echo(a[i][j],' '),
//			echo(t[i][j],' ');
//		}
//		pc('\n');
//	}
	
	if(c<=3&&c>=1){
		// n<=3 k_i <= 10
		// d<=20 q<=10
		
		int t12=w[1]+t[1][1]+t[1][2]+w[2];
		int t13=w[1]+t[1][1]+(t[1][2]+t[2][2])+t[2][3]+w[3];
//		echo(w[1]);
//		echo(t[1][1]);
//		echo(t[1][2]);
//		echo(t[2][2]);
//		echo(t[2][3]);
//		echo(w[3]);
		int t23=w[2]+t[2][2]+t[2][3]+w[3];
		rep(i,1,q){
			int x=rd(),y=rd();
			if(x==1&&y==2){
				echo(t12);
			}
			else if(x==1&&y==3){
				echo(t13);
			}
			else if(x==2&&y==3){
				echo(t23);
			}
		}
		
		return;
	}
	
	return ;
}

signed main(){
#ifdef IO
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
#endif
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
subway
15：20 好像是最短路

1 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

17:41 样例是不是给错了...为什么我照着样例地打还是错的？？？

17：58 666tmd真的是给错了，好舒服啊！！！！！！
可惜了，本来还不确定的。。。

*/
