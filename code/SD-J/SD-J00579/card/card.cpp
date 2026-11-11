#include<bits/stdc++.h>
using namespace std;
#define ll int
queue<ll> q,qq;
ll n,m,a[500045],ans[300045];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	for(ll t=1;t<=n;t++){
		ll b[500005]={0};
		for(ll i=1;i<=n;i++){
			q.push(a[i]);
			b[a[i]]++;
		}
		for(ll i=t;i<=n;i++){
			if(b[a[i]]==0){
				q.push(a[i]);
				b[a[i]]++;
			}else{
				while(q.front()!=a[i]){
					qq.push(q.front());
					q.pop();
				}
				while(!q.empty()){
					b[q.front()]--;
					q.pop();
				}
				while(!qq.empty()){
					q.push(qq.front());
					qq.pop();
				}
				q.push(a[i]);
				b[a[i]]++;
			}
		}
		while(!q.empty()){
			ans[q.front()]++;
			q.pop();
		}
	}
	for(ll i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
