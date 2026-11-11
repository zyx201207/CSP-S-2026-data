#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[200005],ma;
void f(ll ans,ll z,ll x){
	if(ans==m){
		ma=max(ma,z);
		return;
	}
	if(x>n||ans>m||ans+n-x+1<m){
		return;
	}
	if(ans==0){
		f(ans+1,a[x],x+1);
	}else{
		f(ans+1,z&a[x],x+1);
	}
	f(ans,z,x+1);
	return;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	f(0,0,1);
	cout<<ma;
	return 0;
}