// card
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

const int N=500005;
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

int n,m,ans;
int cd[N];
map<int,int> mp;

void solve(){
	n=rd(),m=rd();
	rep(i,1,n) cd[i]=rd();
	
	rep(_,1,n){
		stack<int> s;
		map<int,bool> vis;
		
		rep(i,_,n){
			if(vis.find(cd[i])==vis.end()){
				vis[cd[i]]=1;
				s.push(cd[i]);
			}
			else{
				while(s.top()!=cd[i]) s.pop();
			}
		}
		
		while(!s.empty()){
			int x=s.top();
			mp[x]++;
		}
	}
	
	rep(i,1,m){
		echo(mp[i]," \n"[i==m]);
	}
	
	return ;
}

signed main(){
#ifdef IO
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
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
card

我还是太过于fvv了，连这种东西都写不出模拟...
期望分数：
100 + [0,100] + [0,30] + 0 = [100,230]
希望能多骗一点分数吧...不然两年J3还是太fvv了QAQ
*/
