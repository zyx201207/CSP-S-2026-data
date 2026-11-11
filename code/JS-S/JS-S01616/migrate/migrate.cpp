#include<bits/stdc++.h>
#define ll long long
const int N=2e6+5;
using namespace std;
ll c,t,n,d,ans,a[N],cnt[N],minn[N];
struct node{
	ll id,step;
};
void bfs(ll s){
	for(int i=1;i<=n;i++) cnt[i]=0,minn[i]=1e18;
	queue<node> q;
	q.push({s,0});
	while(q.size()){
		node t=q.front();
		q.pop();
		if(t.step<=minn[t.id]){
			minn[t.id]=t.step;
			cnt[t.id]++;
		}else{
			continue;
		}
		for(ll i=t.id+1;i<=n&&a[i]-a[t.id]<=d;i++){
			q.push({i,t.step+1});
		}
	}
	for(int i=1;i<=n;i++) if(cnt[i]==2) ans++;
}
void solve(){
	ans=0;
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		bfs(i);
	}
	cout<<ans<<endl;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		solve();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
