#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5,M=3e5+5;
ll n,m;
ll a[N],fa[M],num[M],ans[M],aaa[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		fa[a[i]]=-1;
		num[a[i]]++;
	}
	for(ll i=n;i>=1;i--){
		if(fa[a[i]]==-1)fa[a[i]]=a[i+1];
	}
	for(ll i=1;i<=m;i++)aaa[fa[i]]++;
	queue<ll>th;
	for(ll i=1;i<=m;i++){
		if(!aaa[i]){
			th.push(i);
		}
	}
	while(th.size()){
		ll u=th.front();
		th.pop();
		ans[u]+=num[u];
		ans[fa[u]]+=ans[u];
		aaa[fa[u]]--;
		if(!aaa[fa[u]]&&fa[u])th.push(fa[u]);
	}
	for(ll i=1;i<m;i++)cout<<ans[i]<<' ';
	cout<<ans[m]<<'\n';
	return 0;
}
