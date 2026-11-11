#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,k,dp[2][201010][2];
ll a[2010],mx;
void dfs(int x,int y,ll sum){
	if(y==k){
		mx=max(sum,mx);
	}
	if(x==n+1){
		return ;
	}
	dfs(x+1,y+1,sum&a[x]);
	dfs(x+1,y,sum);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>k;
	int f=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i-1)f=1;
	}
	sort(a+1,a+1+n);
	if(f==0&&pow(2,k)==n){
		cout<<1;
	}
	else if(k==n){
		ll sum=pow(2,31);
		for(int i=1;i<=n;i++){
			sum&=a[i];
		}
		cout<<sum;
	}
	else if(k==1){
		ll mx=0;
		for(int i=1;i<=n;i++){
			mx=max(mx,a[i]);
		}
		cout<<mx;
	}
	else if(k==2){
		ll mx=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				mx=max(mx,a[i]&a[j]);
			}
		}
		cout<<mx;
	}
	else if(n<=20){
		dfs(0,0,pow(2,31)-1);
		cout<<mx;
	}
	else{
		cout<<a[n-k+1];
	}
	return 0;
}
