#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+7;
int n,m;
ll a[N],mx=1,ans=0;
void dfs(int x,ll now,int cnt){
	if(x==n+1){
		if(cnt==m){
			ans=max(ans,now);
		}
		return;
	}
	dfs(x+1,(now&a[x]),cnt+1);
	dfs(x+1,now,cnt);
}
void solve1(){
	for(int i=1;i<=30;i++){
		mx+=(1<<i);
	}
	dfs(1,mx,0);
	cout<<ans;
}
void solve2(){
	for(int i=1;i<=n;i++){
		ans=max(ans,a[i]);
	}
	cout<<ans;
}
void solve3(){
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			ans=max(ans,(a[i]&a[j]));
		}
	}
	cout<<ans;
}
void solve4(){
	ans=a[1];
	for(int i=2;i<=n;i++){
		ans=(ans&a[i]);
	}
	cout<<ans;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1) solve2();
	else if(m==2) solve3();
	else if(m==n) solve4();
	else solve1();
	return 0;
}
