#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define str string
#define INF 1e9
ll n,m,a[500005],b[500005],d[500005],e[500005],mx=1;
int main(){
	ios::sync_with_stdio(false);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(ll i = 0;i<n;i++){
		cin >> a[i];
	}
	sort(a,a+n);
	for(ll i = 0;i<n-1;i++){
		b[i]=a[i+1]-a[i];
	}
	d[n-1]=0;
	for(ll i = n-2;i>=0;i--){
		d[i]=d[i+1]+b[i];
	}
	e[n-1]=0;
	for(ll i = n-2;i>=0;i--){
		e[i]=e[i+1]+d[i];
	}
//	for(ll i = 0;i<n;i++)cout << e[i] << ' ';
	ll j=0;
	for(ll i = 1;i<n;i++){
		while(e[j]-e[i]-(a[n-1]-a[i])*(i-j)>m){
			j++;
		}
		mx=max(mx,i-j+1);
	}
	cout << mx;
	return 0;
} 
