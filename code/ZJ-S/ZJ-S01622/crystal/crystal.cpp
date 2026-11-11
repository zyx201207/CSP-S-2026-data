#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll n;
ll m,a[500005];
int main(){
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(ll k=1;k<=n;k++) cin>>a[k];
	sort(a+1,a+n+1);
	ll sum=0;
	ll i;
	for(i=n;i>=1;i--){
		//Çósum 
		if(i==n){
			sum=0;
			for(ll j=1;j<=i-1;j++){
				sum+=a[i]-a[j];
			}
		}
		else sum=sum-i*(a[i+1]-a[i]);
		//cout<<i<<':'<<sum<<endl;
		if(m>=sum)
			break;
	} 
	cout<<i;
	
	return 0;
} 
