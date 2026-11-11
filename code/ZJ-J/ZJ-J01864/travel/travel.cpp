// travel
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

const int N=100005;
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
	string rds(){
		string s="";
		int c=gc();
		while(isspace(c)){
			c=gc();
		}
		while(!isspace(c)&&c!=EOF){
			s+=(char)c;
			c=gc();
		}
		return s;
	}
	void pts(string s){
		for(char c:s)
			pc(c);
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

int n,m;
string c[3],s[3];
string ans;
bool pd1(string a,string b){
	if(a==b) return 1;
	else return 0;
}

bool pd3(char a,char b){
	if(a<='C'&&b<='C') return 1;
	else if(a>='D'&&b>='D') return 1;
	else return 0;
}

void solve(){
	c[1]=rds(),s[1]=rds(),
	c[2]=rds(),s[2]=rds();
	
//	pts(c[1]),
//	pts(s[1]),
//	pts(c[2]),
//	pts(s[2]);
	
	if(pd1(c[1],c[2])) ans+='1';
	else ans+='0';
	
	if(ans[0]=='1'&&s[1][0]==s[2][0]&&s[1][1]==s[2][1]) ans+='1';
	else ans+='0';
	
	char a=s[1][2],b=s[2][2];
	
	if(ans[1]=='1'&&pd3(a,b)) ans+='1';
	else ans+='0';
	
	if(ans[1]=='1'&&pd3(a,b)&&(a-b==1||b-a==1)) ans+='1';
	else ans+='0';
	
	pts(ans);
	
	
	return ;
}

signed main(){
#ifdef IO
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
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
travel


*/
