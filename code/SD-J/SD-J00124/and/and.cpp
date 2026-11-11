#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m;
ll a[200010];
ll ans;
bool pd(int x){
	x++;
	while(x>0){
		if(x%2==1) return 0;
		x/=2;
	}
	return 1;
}
bool f(int k){
	while(k>0){
		if(k%2==1) return 0;
		k/=2;
	}
	return 1;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	bool pdd=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(!pd(a[i])) pdd=1;
		if(f(a[i])) a[i]=0;
	}
	sort(a+1,a+n+1,greater<int>() );
	if(pdd==0){
		ll res=1;
		for(int i=1;i<=m;i++){
			res=res&a[i];
		}
		cout<<res;
		return 0;
	}
	ans=0;
	for(int i=1;i+m<=n;i++){
		ll res=a[i];
		for(int j=i+1;j<=m+i-1;j++) res=res&a[j];
		ans=max(res,ans);
	}
	cout<<ans;
	return 0;
}
/*
int rp=0;
while(1) rp++;
*/ 
