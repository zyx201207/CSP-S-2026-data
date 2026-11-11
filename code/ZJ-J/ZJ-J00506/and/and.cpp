#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
int n,m;
ll a[N];
ll ans;
int cnt[35];
bool vis[N];
int now;
void dfs(int x,ll res,int cab){
	if(cab==m){
		ans=max(ans,res);
		return;
	}
	for(int i=x+1;i<=n;i++) dfs(i,res&a[i],cab+1);
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n<=20){//25pts
		dfs(0,2147483647LL,0);
		cout<<ans;
	}
	else if(m==1){//5pts
		sort(a+1,a+1+n);
		cout<<a[n];
	}
	else if(m==n){//5pts
		ans=2147483647LL;
		for(int i=1;i<=n;i++) ans&=a[i];
		cout<<ans;
	}
	else if(n<=2000&&m==2){//15pts
		dfs(0,2147483647LL,0);
		cout<<ans;
	}
	else{//100pts
		ans=2147483647LL;
		sort(a+1,a+1+n);
		now=n;
		for(int i=1;i<=n;i++) for(int j=0;j<=31;j++) if((1<<j)&a[i]) cnt[j]++;
		for(int i=31;i>=0;i--){
			if(cnt[i]<m) continue;
			for(int j=1;j<=n;j++){
				if(vis[j]) continue;
				if(!((1<<i)&a[j])&&now>m){
					now--;
					vis[j]=1;
				}
			}
		}
		for(int i=1;i<=n;i++){
			if(vis[i]) continue;
			ans&=a[i];
		}
		cout<<ans;
	}
	return 0;
}
