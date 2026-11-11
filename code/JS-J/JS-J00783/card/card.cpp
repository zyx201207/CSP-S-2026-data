#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5010;
ll n,m;
bool ex[N];
ll a[N],ans[N];
void solve(ll x){
	memset(ex,false,sizeof(ex));
	stack<ll> q;
	for(ll i=x;i<=n;i++){
		if(ex[a[i]]){
			while(!q.empty()&&q.top()!=a[i]){
				ex[q.top()]=false;
				q.pop();
			}
		}
		else{
			ex[a[i]]=true;
			q.push(a[i]);
		}
	}
	while(!q.empty()){
		ans[q.top()]++;
		q.pop();
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	for(ll i=1;i<=n;i++){
		solve(i);
	}
	for(ll i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	cout<<endl;
	return 0;
}
