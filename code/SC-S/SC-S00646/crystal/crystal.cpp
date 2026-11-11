#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+5;
int n;
ll m;
ll a[N],pre[N];
bool check(int u,int x){
	ll res=pre[u]-pre[x-1];
	res=a[u]*(u-x+1)-res;
	return res<=m;
}
/*
int c[N*2];
int lowbit(int x){
	return x|(-x);
}
void add(int u,int v){
	while(u<=n){
		c[u]+=v;
		u+=lowbit(u);
	}
}
int ask(int u){
	int res=0;
	while(u){
		res+=c[u];
		u-=lowbit(u);
	}
	return res;
}
I love BIT.
*/
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1]+a[i];
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		int l=1,r=i-1;
		while(l<r){
			int mid=l+r>>1;
			if(!check(i,mid)) l=mid+1;
			else r=mid;
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
}