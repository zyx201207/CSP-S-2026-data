#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,a[500010],ans[300010],b[500010];
queue<ll> v[300010];
void dp(ll x,ll y){
	if(x==n) ans[x]+=y;
	if(!v[a[x]].empty()){
		b[v[a[x]].front()]+=y;
		v[a[x]].pop();
		return;
	}
	ans[a[x]]+=y;
	b[x+1]+=y;
	return;
	
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	std::ios::sync_with_stdio(0);
	std::cin.tie(nullptr);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		v[a[i]].push(i);
		b[i]=1;
	}
	for(ll i=1;i<=n;i++) v[i].pop();
	for(ll i=1;i<=n;i++){
		dp(i,b[i]);
	}
	for(ll i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0; 
}
//挺难的黄题 
//11:30我就写完了，现在11：48，我该干什么呢？  （答案：吃零食）
//装备：波力海苔*3，火腿肠*3，果板*3，鹌鹑蛋*3，魔芋爽*3，一杯水:> 
