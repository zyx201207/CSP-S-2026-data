#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
ll n,m,ans=-1e9,cnt;
ll num[N];
void dfs(ll x,ll w,ll numw,ll flag){
	if(x==n){
		if(w==0){
			ans=max(ans,numw);
		}
		return;
	}
	if(x==flag){
		dfs(x+1,w,numw,flag);
		return;
	}
	if(w>=1) dfs(x+1,w-1,numw & num[x],flag);
	dfs(x+1,w,numw,flag);
	return;
}
int main(){
	freopen("and.in","r",stdin);	
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>num[i];
	}
	if(m==1){
		ll maxn=-1e9;
		for(int i=1;i<=n;i++)
			maxn=max(maxn,num[i]);
		cout<<maxn;
	}else if(m==2){
		ll maxn=-1e9;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ll t=num[i] & num[j];
				maxn=max(maxn,t);
			}
		}
		cout<<maxn;
	}else if(n==m){
		ll maxn=num[1];
		for(int i=2;i<=n;i++){
			maxn=maxn & num[i];
		}
		cout<<maxn;
	}else if(n<=20){
		for(int i=1;i<=n;i++){
			dfs(1,m-1,num[i],i);
		}
		cout<<ans<<"\n";
	}
	return 0;
}
