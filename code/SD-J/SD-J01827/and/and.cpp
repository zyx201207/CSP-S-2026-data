#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,a[200005],cnt=0;
bool cmp(ll x,ll y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==2){
		for(ll i=1;i<=n;i++){
			for(ll j=i+1;j<=n;j++){
				cnt=max(cnt,a[i]&a[j]);
			}
		}
		cout<<cnt;
	}else{
		sort(a+1,a+n+1,cmp);
		cnt=a[1];
		for(ll i=2;i<=m;i++){
			cnt=cnt&a[i];
		}
		cout<<cnt;
	}
	return 0;
}
