#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=5e5+5;
ll n,m,a[N],maxx=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	ll l=1,r=1,ans;
	while(l<=r&&r<=n){
		ans+=(a[r]-a[r-1])*(r-l);
		if(ans<=m){
			maxx=max(maxx,r-l+1);
		}else{
			while(ans>m){
				ans-=a[r]-a[l];
				l++;
			}
			maxx=max(maxx,r-l+1);
		}
		r++;
	}
	cout<<maxx<<endl;
	return 0;
} 
