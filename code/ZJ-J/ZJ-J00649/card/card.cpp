#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[500010],ans[300010];
int main(){
	freopen("card.in",r,stdin);
	freopen("card.out",w,stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>a[i];
	for(ll i=1;i<=n;i++){
		ll v[300010]={};
		deque<ll> que;
		for(ll j=i;j<=n;j++){
			if(v[a[j]]==0){
				que.push_back(a[i]);
				v[a[j]]++;
			}
			else{
				while(que.size()>0){
					if(que.back()==a[j]){
						que.pop_back();
						break;
					}
					v[que.back()]--;
					que.pop_back();
				}
				que.push_back(a[j]);
			}
		}
		for(ll j=1;j<=m;j++){
			if(v[j]) ans[j]++;
		}
	}
	for(ll i=1;i<=m;i++) cout<<ans[i]<<' ';
	return 0;
} 
