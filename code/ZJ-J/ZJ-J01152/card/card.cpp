#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=5e5+5,M=3e5+5;
ll n,m,a[N],last[M],ans[M],pre[N],b[N],inq[N];
ll lowbit(ll x){
	return x&-x;
}
void add(ll x,ll k){
	while(x<=n){
		b[x]+=k;
		x+=lowbit(x);
	}
}
ll check(ll x){
	ll ans=0;
	while(x>0){
		ans+=b[x];
		x-=lowbit(x);
	}
	return ans;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	bool flag=true;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		pre[i]=last[a[i]];
		last[a[i]]=i;
		if(a[i]<a[i-1]) flag=false;
	}
	if(flag){
		for(ll i=1;i<=n;i++){
			if(a[i]!=a[i-1]){
				ans[a[i-1]]=i-1;
			}
		}
		ans[a[n]]=n;
		for(ll i=1;i<=m;i++){
			cout<<ans[i]<<" ";
		}
		return 0;
	}
	for(ll i=1;i<=n;i++){
		stack<ll> st;
		memset(inq,0,sizeof(inq));
		for(ll j=i;j<=n;j++){
			if(inq[pre[j]]){
				while(st.size()&&a[st.top()]!=a[j]) inq[st.top()]=0,st.pop();
				if(st.size()) st.pop();
			}
			st.push(j);
			inq[j]=1;
		}
		while(st.size()){
			ans[a[st.top()]]++;
			st.pop();
		}
	}
	for(ll i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
