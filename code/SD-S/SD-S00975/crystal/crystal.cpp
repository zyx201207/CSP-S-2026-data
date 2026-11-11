#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll N=1e6+10;
ll n,m;
ll a[N];
ll sm[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i]; 
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sm[i]=sm[i-1]+a[i];
	}
	
	ll j=1;
	ll ans=1; 
	for(int i=1;i<=n;i++){
		while(a[i]*(i-j+1)-sm[i]+sm[j-1]>m){
			j++;
		}
		ans=max(ans,i-j+1);
	}
	cout<<ans<<'\n';
	return 0;
}
/*
必有一颗水晶能量不变，也就是最大的水晶
双指针，因为水晶左端点必定不减，是的？
做前缀和是否更好做？
a_i*(i-j+1)-(sm_i-sm_{j-1}) 注意j-1边界问题 
*/ 
