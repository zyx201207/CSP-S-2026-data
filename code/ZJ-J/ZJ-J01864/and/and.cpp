// and
#include<bits/stdc++.h>

#define int long long

#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define repp(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);++i)
#define pper(i,a,b) for(int i=(a);i>(b);++i)

#define VI vector<int>
#define pb push_back
#define m_p make_pair
#define PII pair<int,int>
#define mms(a,b) memset((a),(b),sizeof(a))

#define IO

using namespace std;

const int N=200005;
const int M=3000005;
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
	void print(int n){
		if(n<0) pc('-'),n=-n;
		if(n>9) print(n/10);
		pc(n%10^48);
	}
	void echo(int n,char c='\n'){
		print(n),pc(c);
	}
	template <typename T>
	bool umax(T& a,const T& b){
		return b>a?a=b,1:0;
	}
	template <typename T>
	bool umin(T& a,const T& b){
		return b<a?a=b,1:0;
	}
}using namespace Fast;

int n,m,ans=-INF,mx=-INF;
int _=1;
int a[N];

bool pd(int x){
	rep(i,0,20){
		if(x==((1<<i)-1)) return 1;
	}
	return 0;
}

void solve(){
	n=rd(),m=rd();
	rep(i,1,n){
		a[i]=rd();
		umax(mx,a[i]);
		if(_&&pd(a[i])==0) _=0;
	}
	
	if(m==1){echo(mx);return;}
	if(n<=2000&&m==2){
		rep(i,1,n){
			rep(j,i+1,n){
				umax(ans,a[i]&a[j]);
			}
		}
		echo(ans);
		return;
	}
	if(m==n){
		ans=a[1];
		rep(i,2,n){
			ans&=a[i];
		}
		echo(ans);
		return;
	}
	// 25pts
	
	sort(a+1,a+n+1,greater<int>());
	
	if(_){
		echo(a[m]);
		return;
	} // A
	
	ans=a[1];
	
	rep(i,2,m){
		ans&=a[i];
	}
	
	echo(ans);
	
	
	return ;
}

signed main(){
#ifdef IO
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
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
and


*/
