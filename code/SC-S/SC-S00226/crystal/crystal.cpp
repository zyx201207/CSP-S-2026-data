#include<bits/stdc++.h>
using namespace std;
long long n,ans,mod=-1;
long long a[500005],c[500005],flag[500005];
int dfs(int i,long long m){
	if(i<1||i>n){
		return 0;
	}
	else if(flag[i]==0){
		flag[i]=1;
		m-=c[i];
		if(m<0){
			ans-=1;
			return 0;
		}
		ans+=2;
		return dfs(i+1,m)+dfs(i-1,m);
	}
	else{
		ans-=1;
		return 0;
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long s=0;
	for(int i=1;i<=n;i++){
		c[i]=abs(a[i]-a[i-1]);
	}
	for(int i=1;i<=n;i++){
		dfs(i,m);
		mod=max(mod,ans);
		ans=0;
	}
	cout<<mod;
	return 0;
}