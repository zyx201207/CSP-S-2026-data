#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define down(i,a,b) for(int (i)=(a);(i)>=(b);(i)--)
void file(){
	 freopen("crystal.in","r",stdin);
	 freopen("crystal.out","w",stdout);
}
const ll N=500009;
const ll INF=1e15;
const ld ERR=0.000000000001;
ll n,m,a[N];
void input(){
	cin>>n>>m;
	rep(i,1,n)cin>>a[i];
} 
ll ans=0;
multiset<ll> s;
void dfs(ll now){
	if(now==m+1){
		rep(i,1,n)s.insert(a[i]);
		while(!s.empty()){
			ans=max(ans,(ll)s.count((*s.begin())));
			s.erase(s.begin());
		} 
		return;
	}
	rep(i,1,n){
		a[i]++;
		dfs(now+1);
		a[i]--;
	}
}
void solveDFS(){
	ans=0;
	dfs(1);
	cout<<ans<<endl;
}
void solveBF(){
	ans=0;
	sort(a+1,a+1+n);
	rep(i,1,n){
		ll l=i-1;
		ll cnt=1,sum=0;
		while(1<=l){
			ll deltaL=0;
			if(l<1)deltaL=INF;
			else deltaL=abs(a[i]-a[l]);
			if(sum+deltaL>m)break;
			l--;
			cnt++;
			sum+=deltaL;
		}
//		cout<<i<<" "<<cnt<<endl;
		ans=max(ans,cnt);
	}
	cout<<ans<<endl;
}
void solve(){
	sort(a+1,a+1+n);
	ans=1;
	ll l=1,sum=0;
	rep(r,2,n){
		sum+=(r-l)*(a[r]-a[r-1]);
		while(sum>m){
			sum-=abs(a[l]-a[r]);
			l++;
		}
		ans=max(ans,r-l+1);
	}
	cout<<ans<<endl;
}
int main(){
	file();
	input();
	if(n<=5&&m<=10)
		solveDFS();
	else if(n<=5000)
		solveBF();
	else
		solve();
	return 0;
}

