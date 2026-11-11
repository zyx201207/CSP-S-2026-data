#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll maxn=3e5+10;

ll n,m;
ll a[maxn],ans[maxn],vis[maxn];
queue<ll> q,q1;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>a[i];
	for(ll i=1;i<=n;i++){
		for(ll j=i;j<=n;j++){
			while(!q.empty()){
				int x=q.front();
				if(x==a[j]) break;
				else{
					q1.push(x);
					q.pop();
				}
			}
			while(!q.empty()) q.pop();
			while(!q1.empty()){
				int x=q1.front();
				q1.pop();
				q.push(x);
			}
			q.push(a[j]);
		}
		memset(vis,0,sizeof(vis));
		while(!q.empty()){
			int x=q.front();
			q.pop();
			if(!vis[x]){
				ans[x]++;
				vis[x]=1;
			}
		}
	}
	for(ll i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}
