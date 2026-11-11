#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,mx=INT_MIN;
ll a[200011];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=0;i<=n;i++){
		for(int j=i+1;j<=n;j+=m){
			ll x=a[i];
			for(int k=m-1;k>=0;k--){
				x&=a[j-k];
			}
			mx=max(mx,x);
		}
	}
	cout<<mx;
	return 0;
}
