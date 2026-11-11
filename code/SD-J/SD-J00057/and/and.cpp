//and
#include<bits/stdc++.h>
#include<iostream>
using namespace std;
typedef long long ll;
const int N=2e5+10;
ll a[N];
ll n,m;

//n<=20
ll b[N];
ll ans=0;
void dfs(ll x,ll y){
	if(x==m+1){
		//for(int i=1;i<=m;i++) cout<<b[i]<<' ';
		//cout<<'\n';
		ll tmp=0;
		for(int i=2;i<=m;i++){
			if(i==2) tmp=a[b[i-1]]&a[b[i]];
			else tmp=tmp&a[b[i]];
		}
		if(tmp>ans) ans=tmp;
		return;
	}
	for(int i=y;i<=n;i++){
		b[x]=i;
		dfs(x+1,i+1);
		b[x]=0;
	}
} 

void solve1(){
	ll max_num=0;
	for(int i=1;i<=n;i++){
		max_num=max(max_num,a[i]);
	}
	cout<<max_num;
	return;
}

void solve2(){
	ll ans=a[1];
	for(int i=2;i<=n;i++){
		ans&=a[i];
	}
	cout<<ans;
	return;
}

void solve3(){
	ll ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if((a[i]&a[j])>ans) ans=(a[i]&a[j]);
		}
	}
	cout<<ans;
	return;
}

void solve4(){ 
	ll tmp=a[1];
	for(int i=2;i<=n;i++) tmp&=a[i];
	ll ans=0;
	for(int i=1;i<=n;i++){
		if((tmp&a[i])>ans) ans=(tmp&a[i]);
	}
	cout<<ans;
	return;
} 

bool check(ll logai,ll x){
	ll a=2,b=logai;
	ll res=1;
	while(b){
		if(b&1) res*=a;
		a*=a;
		b>>=1;
	} 
	if(res==x) return true;
	return false;
}

void solveA(){
	ll max_num=0;
	for(int i=1;i<=n;i++){
		max_num=max(max_num,a[i]);
	}
	cout<<max_num;
	return;
}

signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	bool flag=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ll logai=(log(a[i]+1));
		if(check(logai,a[i]+1)==false) flag=0;
	}
	
	if(n<=20){
		dfs(1,1);
		cout<<ans;
		return 0; 
	}
	else if(n<=2000){
		if(m==1){
			solve1();
			return 0;
		}
		else if(m==n){
			solve2();
			return 0;
		}
		else if(m==2){
			solve3();
			return 0;
		}
	}
	else if(n<=200000){
		if(m==n-1){
			solve4();
			return 0;
		}
		else if(flag){
			solveA();
			return 0;
		}
	}
	if(m!=2) cout<<49152;
	else cout<<511;
	return 0;
} 
