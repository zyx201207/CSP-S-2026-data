#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2*2*1e5;
ll n,a[N],l,r,ans;
char b[N];
int main(){
	freopen("string.in","r",stdin); 
	freopen("string.out","w",stdout); 
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	l=1;
	r=n;
	while(l<r){
		if(a[l]==0){
			l++;
		}
		if(a[r]==0){
			r--;
		}
		ll small=min(a[l],a[r]);
		if(b[l]!=b[r]){
			ans+=small;
		}
		a[l]-=small;
		a[r]-=small;
	}
	cout<<ans;
	return 0;
}
