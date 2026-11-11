#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=5e5+10;
int n,ans=0;
ll m,a[N],sum[N];
int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		ll num=1ll*(i-1)*a[i]-sum[i-1];
		if(m>=num) ans=i;
		//else break;
	}
	cout<<ans;
	return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/
