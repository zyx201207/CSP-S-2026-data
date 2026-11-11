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
const int N=500005;
int n,m,ans,a[N];
void run(){
	cin>>n>>m;
	rep(i,n)cin>>a[i];
	sort(a,a+n);
	ans=1;
	int s=0,l=0;
	rep(i,n){
		s+=a[i];
		while(m<a[i]*(i-l+1)-s){
			s-=a[l];l++;
		}
		Mx(ans,i-l+1);
	}
	cout<<ans<<"\n";
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	FIO("crystal");
	int T=1;
	// cin>>T;
	while(T--)
		run();
	re 0;
}