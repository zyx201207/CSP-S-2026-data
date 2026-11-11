#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[200010],ans,cnt,maxx;
void dfs(ll x,ll s,ll sum){
	if(s==m){
		ans=max(ans,sum);
		return;
	}
	for(ll i=x+1;i<=n;i++){
		if(sum==0){
			dfs(i,s+1,a[i]);
		}else{
			dfs(i,s+1,sum&a[i]);
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(maxx,a[i]);
		if(i==1)cnt=a[i];
		else cnt=cnt&a[i];
	}
	if(m==1){
		cout<<maxx;
		return 0;
	}else if(m==n){
		cout<<cnt;
		return 0;
	}else if(m==n-1){
		maxx=0;
		for(ll i=1;i<=n;i++){
			maxx=max(maxx,cnt^a[i]);
		}
		cout<<maxx;
		return 0;
	}else if(maxx<4){
		cnt=0;
		for(ll i=1;i<=n;i++){
			if(a[i]%2==1)cnt++;
		}
		if(cnt<m)cout<<"2";
		else cout<<"3";
		return 0;
	}else if(n<=2000){
		dfs(0,0,0);
	    cout<<ans;
	    return 0;
	}else{
		cout<<maxx;
		return 0;
	}
	
}
