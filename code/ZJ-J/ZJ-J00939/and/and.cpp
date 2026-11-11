#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define pb push_back
const int mo=1e9+7;
ll mod(ll x){
	return (x%mo+mo)%mo;
}
const int N=2e5+5;
int n,m,ans,a[N];
void dfs(int i,int j,int sum){
	if(j==0){
		ans=max(sum,ans);
		return;	
	} 
	for(int k=i+1;k+j-1<=n;k++)
		dfs(k,j-1,(sum&a[k]));
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n<=20){
	 	for(int i=1;i+m-1<=n;i++)
	 		dfs(i,m-1,a[i]);
	 	cout<<ans;
	}else if(m==1){
		int mx=0;
		for(int i=1;i<=n;i++) mx=max(a[i],mx);
		cout<<mx;
	}else if(m==n){
		ans=a[1];
		for(int i=2;i<=n;i++)
			ans&=a[i];
		cout<<ans;
	}else if(m==2){
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				ans=max(ans,(a[i]&a[j]));
		cout<<ans;
	}else if(m==n-1){
		int sum=a[1];
		for(int i=2;i<=n;i++)
			sum&=a[i];
		for(int i=1;i<=n;i++)
			ans=max(ans,(sum^a[i]));
	}else{
		sort(a+1,a+n+1,greater<int>());
		int ans=a[1];
		for(int i=1;i<=m;i++)
		 	ans&=a[i];
		cout<<ans;
	}
	return 0;
}

