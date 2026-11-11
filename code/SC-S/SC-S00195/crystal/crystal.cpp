//特殊情况 等差数列 
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAN=5e5+10;
ll a[MAN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll n,m,ans=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	ll g=a[2]-a[1];//差 
	ll sum=m/g;//最多操作几次 
	for(int i=2;i<=n;i++){
		if(sum-(i-1)<=0) break;
		else sum-=(i-1),ans=i;
	}
	cout<<ans;
		
	return 0;
} 