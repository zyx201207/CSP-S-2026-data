// string
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

int n,m,ans;
int num;
char c;

struct Node{
	int num;
	char c; 
	bool operator == (const Node& o ) const {
		return num==o.num&&c==o.c;
	}
};



void solve(){
	n=rd();
	deque<Node> a;
	rep(i,1,n){
		int x=rd();
		char c=gc();
		a.pb((Node){x,c});
	}
	if(n==1){echo(0);return;}
	
//	cout<<a.front().num;
	
	while((int)a.size()>1){
		auto& tmp1=a.front();
		auto& tmp2=a.back();
		
		int num1=tmp1.num;
		char cr1=tmp1.c;
		int num2=tmp2.num;
		char cr2=tmp2.c;
		
		if(num1>num2){
			if(cr1!=cr2){
				ans+=num2;
			}
			num1-=num2;
			a.pop_back();
			
			a.pop_front();
			a.push_front((Node){num1,cr1});
		}
		else if(num1<num2){
			if(cr1!=cr2){
				ans+=num1;
			}
			num2-=num1;
			a.pop_front();
			
			a.pop_back();
			a.push_back((Node){num2,cr2});
		}
		else{
			ans+=num1;
			a.pop_front();
			a.pop_back();
		}
	}
	
	echo(ans);

	
	
	
	return ;
}

signed main(){
#ifdef IO
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
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
string


*/
