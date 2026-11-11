#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(auto i=(a);i<=(b);i++)
#define REP(i,a,b) for(auto i=(a);i>=(b);i--)
#define FORK(i,a,b,k) for(auto i=(a);i<=(b);i+=(k))
#define REPK(i,a,b,k) for(auto i=(a);i>=(b);i-=(k))
#define fi first
#define se second
#define gc getchar()
#define pc putchar
#define pln pc(10);
#define eb emplace_back
#define pb push_back
#define mkpr make_pair
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
template<class T>
void ckmx(T& a,T b){
	a=max(a,b);
}
template<class T>
void ckmn(T& a,T b){
	a=min(a,b);
}
template<class T>
void read(T& x){
	x=0;
	int f=1;
	char ch=gc;
	while(!isdigit(ch)){
		if(ch=='-')f=-1;
		ch=gc;
	}
	while(isdigit(ch)){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=gc;
	}
	x*=f;
}
void io(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
}
const int maxn=5e5+5;
int n;
ll m,a[maxn];
ll pre[maxn];
void solve(int testid){
	read(n);
	read(m);
	FOR(i,1,n){
		read(a[i]);
	}
	sort(a+1,a+n+1);
	FOR(i,1,n){
		pre[i]=pre[i-1]+a[i];
	}
	int ans=0;
	int l=1;
	FOR(r,1,n){
		while((r-l+1)*a[r]-(pre[r]-pre[l-1])>m){
			l++;
		}
		ckmx(ans,r-l+1);	
	}
	printf("%d\n",ans);
}
int main(){
	io(); 
	int T=1;
	FOR(_,1,T){
		solve(_);
	}
	return 0;
}

