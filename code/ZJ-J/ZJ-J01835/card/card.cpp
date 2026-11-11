#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN=5e5+10;
ll n,m,a[MAXN],ans[MAXN];bool vis[MAXN];
deque <ll>q; 
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(vis[a[j]]){
				while(!q.empty()&&vis[a[j]]){
					ll tp=q.front();
					vis[tp]=0;
					q.pop_front();
				}
			}
			q.push_front(a[j]);
			vis[a[j]]=1;
		}
		while(!q.empty()){
			ll tp=q.front();
			vis[tp]=0;
			ans[tp]++;
			q.pop_front();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i];
		if(i<m) cout<<" ";
	}
	return 0;
}
