#include<bits/stdc++.h>
#define vi vector<int>
#define pii pair<int,int>
#define rept(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) rept(i,0,n)
#define F first
#define S second
#define all(a) a.begin(),a.end()
#define sz(a) ((int)a.size())
#define il inline
#define re return
#define pb push_back
#define db double
#define ld long db
#define int long long
using namespace std;
template<typename T>void Mx(T&x,T y){if(x<y)x=y;}
template<typename T>void Mi(T&x,T y){if(x>y)x=y;}
const int MOD=998244353,INF=1000000000000000000;
void FIO(string s){
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}
const int N=2000006;
int n,d,a[N];
int tl[N],tr[N];
int sl[N],sr[N];
void run(){
	cin>>n>>d;
	rep(i,n)cin>>a[i];
	int la=0;
	rep(i,n){
		while(a[i]-a[la]>d)la++;
		tl[i]=la;
	}
	la=n-1;
	for(int i=n-1;~i;i--){
		while(a[la]-a[i]>d)la--;
		tr[i]=la;
	}
	rep(i,n)sl[i]=sr[i]=0;
	rep(i,n){
		if(tl[i]<i&&tr[tl[i]]==i){
			sl[i]=sl[tl[i]];
		}
		if(i==n-1)sl[i]+=i-tl[i];
		else sl[i]+=tl[i+1]-tl[i];
	}
	for(int i=n-1;~i;i--){
		if(tr[i]>i&&tl[tr[i]]==i){
			sr[i]=sr[tr[i]];
		}
		if(!i)sr[i]+=tr[i];
		else sr[i]+=tr[i]-tr[i-1];
	}
	int ans=0;
	rept(i,2,n-1){
		if(tl[i]>=i-1||tr[i-1]<=i)continue;
		int cl=tl[i+1]-tl[i];
		if(tr[tl[i]]==i&&tl[i-1]==tl[i])cl+=sl[tl[i]];
		int cr=tr[i-1]-tr[i-2];
		if(tl[tr[i-1]]==i-1&&tr[i]==tr[i-1])cr+=sr[tr[i-1]];
		// if(cl&&cr)cout<<i<<" "<<cl<<" "<<cr<<"\n";
		ans+=cl*cr;
	}
	cout<<ans<<"\n";
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	FIO("migrate");
	int T=1;
	int _C;
	cin>>_C>>T;
	while(T--)
		run();
	re 0;
}