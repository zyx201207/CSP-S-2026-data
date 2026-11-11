#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
ll n,m,a[N];
ll sum=0;
ll ans=-1;
void dfs(ll pos,ll kind,ll sum){
	if(pos>n){
		if(kind==m){
//			cout<<'x'<<'\n';
			ans=max(ans,sum);
		}
		return;
	}
//	cout<<a[pos+1]<<' '<<sum<<'\n';
	dfs(pos+1,kind,sum);
	dfs(pos+1,kind+1,sum&a[pos+1]);
}
void solve_25(){
	for(int i=1;i<=n;++i){
		dfs(i,1,a[i]);
	}
	cout<<ans;
	return;
}
void solve_50(){
	if(m==1){
		for(int i=1;i<=n;++i){
			ans=max(ans,a[i]);
		}
		cout<<ans;
		return;
	}
	else if(m==n){
		for(int i=2;i<=n;++i){
			a[i]&=a[i-1];
		}
		cout<<a[n];
		return;
	}
	else if(m==2){
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				if(i==j) continue;
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
		return;
	}
}
bool check(ll x){
	ll t=x+1;
	while(t%2==0){
		t/=2;
	}
	if(t==1){
		return 1;
	}
	else{
		return 0;
	}
}
bool cmp(ll x,ll y){
	return x>y;
}
void solve_65(){
	sort(a+1,a+n+1,cmp);
	int ans=a[1];
	for(int i=2;i<=m;++i){
		ans&=a[i];
	}
	cout<<ans;
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m;
	bool f=1;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		if(!check(a[i])){
			f=0;
		}
	}
	if(n<=20){
		solve_25();
	}
	else if(n<=2000){
		solve_50();
	}
	else if(n<=2e5&&f){
		solve_65();
	}
//	if(check(15)){
//		cout<<"Yes";
//	}
	return 0;
/*
4 2
3 15 12 12
5 3
31 3 1 15 7
*/
}
