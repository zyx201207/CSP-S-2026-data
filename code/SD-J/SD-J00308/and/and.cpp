#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll const N=1e6+10;
ll n,m,a[N],Min=N;
bool cmp(ll x,ll y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	for(ll i=2;i<=m;i++){
		Min=min(a[i],Min);
	}
	cout<<Min;
	return 0;
}
