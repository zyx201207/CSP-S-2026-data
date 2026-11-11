#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
ll n,m;
ll a[N];
ll ans;
void solve1(){
	sort(a+1,a+1+n); 
	for(int i=1;i<=n;i++){//暴力O(n^2) 
		ll k=0,cnt=1;
		priority_queue<ll> pq;
		for(int j=1;j<i;j++){	
			pq.push(-a[i]+a[j]);
		}
		while(!pq.empty()&&k<=m){
			ll x;
			x=-pq.top();//手动小根堆 
			pq.pop();
			if(x+k<=m){
				k+=x;
				cnt++;
			}
		}
		ans=max(ans,cnt);
	}
	cout<<ans<<" ";
}
void solve2(int m){
	ll k=1;
	ans=0;
	m+=1;
	while(m){
		if(m-k>0){
			m-=k;
		}else{
			break;
		}
		k++;
		ans++;
	}
	cout<<ans+1<<endl;
}
void solve3(int m,int d){
	m+=1;
	ll k=d;
	ans=1;
	while(m){
		if(m-k>0){
			m-=k;
		}else{
			break;
		}
		k+=d;
		ans++;
	}
	cout<<ans;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=5000){
		solve1();
		return 0;
	}
	bool fl2=true;
	for(int i=1;i<=n;i++){
		if(a[i]!=i){
			fl2=false;
			break;
		}
	}
	if(fl2){
		solve2(m);
		return 0;
	}
	bool fl3=true;
	int t=a[2]-a[1];
	for(int i=2;i<=n;i++){
		if(t!=a[i]-a[i-1]){
			fl3=false;
			return 0;
		}
	}
	if(fl3){
		solve3(m,t);
		return 0;
	}
	return 0;
} 
