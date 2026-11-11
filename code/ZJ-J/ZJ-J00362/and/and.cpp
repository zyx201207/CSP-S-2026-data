#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N=2e5+5;
ll n,m,a[N],ans=0;
void dfs(ll k,ll last,ll sum,ll t){
	if(t==m){
		ans=max(ans,sum);
		return ;
	}
	if(k>n){
		return ;
	}
	for(int i=last;i<=n;i++){
		int q;
		if(sum==0){
			q=a[i];
		}else{
			q=sum&a[i];
		}
		dfs(k+1,i+1,q,t+1);
		dfs(k+1,last,sum,t);
	}
	return ;
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,1,0,0);
	cout<<ans;
	return 0;
}
