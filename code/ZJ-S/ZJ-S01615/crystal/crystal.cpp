#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll n,m,a[500005],sum[500005],ans;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	for(ll l=1,r=1;r<=n;r++){
		if(l!=r){
			while(l<r){
				ll k=(r-l) * a[r] - (sum[r-1] - sum[l-1]);
				if(k>m){
					l++;
				}else{
					break;
				}
			}
		}
		ans=max(ans,r-l+1);
	}
	cout << ans;
	
	return 0;
} 
