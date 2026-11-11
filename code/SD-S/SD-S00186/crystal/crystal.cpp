#include <bits/stdc++.h>
#define ll long long  
using namespace std;
const int N=5e5+5;
ll n,m,a[N],sum,ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(ll i=1,j=1;i<=n;i++){
		ll len=(i-j);
		for(;j<i;j++){
			if(a[i]*len-sum<=m) break;
			sum-=a[j];
			len--;
		}
		sum+=a[i];
		ans=max(ans,len+1);
	}
	cout<<ans<<"\n";
	return 0;
}
//1 1000000000000000000
//-1000000000000
//ans=1

//10 8999998965677
//114514 -1 1000000000000 -1000000 1919810 2 -3 -2 3 
//ans=10

//13 0
//-1 1217131 1237813 377121 1313 313535 1918181798732 1918181798732 1918181798732 1918181798732 1918181798732 1918181798732 1918181798732
//ans=7

//8 6
//-1000000000000 1000000000000 7 8 9 10 2 10 
//ans=5

//10 6
//-4 0 1 3 -2 -4 -5 1 2 -2 
//ans=4 
