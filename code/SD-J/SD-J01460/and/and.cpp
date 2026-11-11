#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=200010;
ll n,m;
ll a[N];
ll maxn=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(ll i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(a[i]>maxn) maxn=a[i];
	}
	if(m==1){
		cout<<maxn;
		return 0;
	}
	if(m==n){
		maxn=a[1]&a[2];
		for(int i=3;i<=n;i++){
			maxn=maxn&a[i];
			if(maxn==0)
				break;
		}
		cout<<maxn;
		return 0;
	}
	maxn=0;
	int ii,jj;
	for(ll i=1;i<=n;i++){
		for(ll j=i+1;j<=n;j++){
			if(maxn<=(a[i]&a[j])){
				maxn=a[i]&a[j];
				ii=i;
				jj=j;
			}
		}
	}
	if(m==2){
		cout<<maxn;
		return 0;
	}
	a[ii]=0;
	a[jj]=0;
	m-=2;
	while(m--){
		ll b=maxn;
		maxn=0;
		for(ll i=1;i<=n;i++){
			a[i]=b&a[i];
			if(maxn<a[i]){
				maxn=a[i];
				ii=i;
			}
		}
		a[ii]=0;
	}
	cout<<maxn;
	return 0;
}
