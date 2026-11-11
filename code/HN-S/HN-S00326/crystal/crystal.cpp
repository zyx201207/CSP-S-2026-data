//crystal
#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
constexpr ll N=1e5+5,M=5*N,K=5000;
ll n,m,a[M],k,ans=0;
bool A=1,B=1;
void solve(ll x){
	ll l=x,cnt=m;
	ll tot=1;
	while(cnt){
		l--;
		if(l==0) break;
		k=min(a[x]-a[l],cnt);
		if(a[l]+k==a[x]) tot++;
		cnt-=k;
	}
	ans=max(ans,tot);
	return ;
}
int main(){
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(ll i = 1;i<=n;i++){
		cin >> a[i];
		if(a[i]!=i)A=0;
		if(a[i]-a[i-1]!=a[i-1]-a[i-2]&&i>2) B=0;
	}
	if(n==1){
		cout << 1;
		return 0;
	}
	if(A==1){
		for(ll i = 1;i<=n;i++){
			if(i*(i+1)/2==m){
				cout << i+1;
				return 0;
			}
			if(i*(i+1)/2>m){
				cout << i;
				return 0;
			}
		}
		cout << n;
		return 0;
	}
	if(B==1){
		for(ll i = 1;i<=n;i++){
			if(i*(i+1)/2*(a[2]-a[1])==m){
				cout << i+1;
				return 0;
			}
			if(i*(i+1)/2*(a[2]-a[1])>m){
				cout << i;
				return 0;
			}
		}
		cout << n;
		return 0;
	}
	sort(a+1,a+1+n);
	for(ll i = 1;i<=n;i++){
		solve(i);
	}
	cout << ans;
	return 0;
}
/*
5 5 
1 2 4 8 9

3


5 8 
-3 -1 2 2 7

4
*/
