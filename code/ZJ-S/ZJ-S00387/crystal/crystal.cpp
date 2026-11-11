#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N=5e5+5;
ll n,m,a[N],dp[N];
ll f(int x){
	ll mx=a[x],t=m,sum=0;
	for(int i=x;i>=1;i--){
		if(mx-a[i]>t){
			break;
		}
		t-=(mx-a[i]);
		sum++;
	}
	return sum;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		dp[i]=max(dp[i-1],f(i));
	}
	cout<<dp[n];
	return 0;
}
