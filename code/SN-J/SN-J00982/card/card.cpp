#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,flagA,flagB,a[500010];
ll ans[300010];
ll b[300010],nn;
deque<ll>q[300010];
void tepanA(){
	for(int i=1;i<=n;i++) ans[a[i]]=i;
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return;
}
void baoli(ll now){
	for(int i=now;i<=n;i++){
		if(q[a[i]].front()==q[a[i]].back()) ans[a[i]]++;
		else{
			ans[a[i]]++;
			i=q[a[i]].back();
		}
	}
	return;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i-1]>=a[i]) flagA=1;
	}
	if(!flagA){
		tepanA();
		return 0;
	}
	for(int i=1;i<=n;i++){
		if(a[i]!=a[i-1]){
			nn++;
			b[nn]=a[i];
		}
	}
//	memset(a,0,sizeof(a));
//	for(int i=1;i<=nn;i++) a[i]=b[i];
//	n=nn;
	for(int i=1;i<=n;i++) q[a[i]].push_back(i);
	for(int i=1;i<=n;i++) baoli(i);
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}
