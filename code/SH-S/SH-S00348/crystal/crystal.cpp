#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
ll a[N],b[N];
int main(){
	ios_base::sync_with_stdio(false);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	
	for(int i=1;i<=n;i++){
		b[i]=a[i+1]-a[i];
	}
	b[n]=5e12;
	ll sum=0,l=1,r=1;
	ll mx=0;
	while(l<=r){
		while(r+1<=n&&sum+(ll)(r-l+1)*b[r]<=m){
			sum+=(ll)(r-l+1)*b[r];
			r++;
		}
		mx=max(mx,r-l+1);
		sum-=(ll)(a[r]-a[l]);
		l++;
	}
	cout<<mx;
} 
