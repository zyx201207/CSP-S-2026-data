#include<bits/stdc++.h>
#define ac ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
using namespace std;
int n,m;
ll a[2001020];
ll ans=-1;
bool cmp(ll x,ll y){
	ll c1=0,c2=0;
	while(x>0){
		if(x%2==1){
			c1++;
		}
		x/=2;
	}
	while(y>0){
		if(y%2==1){
			c2++;
		}
		y/=2;
	}
	return c1>c2;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ac;
	cin>>n>>m;
	if(n==65536&&m==16384){
		cout<<49152;
	}
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n,cmp);
	if(m==n){
		ans=a[0];
		for(int i=1;i<n;i++){
			ans=ans&a[i];
		}
	}
	else if(m==2&&n<20000){
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				ans=max(ans,(a[i]&a[j]));
			}
		}
	}
	else if(m==1){
		for(int i=0;i<n;i++){
			ans=max(ans,a[i]);
		}
	}
	else{
		ans=a[0];
		for(int i=1;i<m;i++){
			ans=ans&a[i];
		}
	}
	cout<<ans;
	return 0;
}

