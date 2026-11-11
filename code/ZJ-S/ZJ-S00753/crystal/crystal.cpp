#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
ull A[1000000000005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll n;
	ull m;
	cin>>n>>m;
	for(ull i=0;i<n;i++){
		cin>>A[i];
	}
	sort(A,A+n);
	ll ans=1;
	for(ll i=0;i<n;i++){
		if (A[i+1]-A[i]>m)
		break;
		else if(A[i+1]-A[i]<=m){
			m=m-A[i+1]-A[i];
			ans++;		
		}
	}
	cout<<ans;
	return 0;
}