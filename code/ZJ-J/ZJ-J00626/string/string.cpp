#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n;
ll a[200005];
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	ll l=1,r=n;
	ll cnt=0;
	while(l<r){
		//cout<<l<<' '<<a[l]<<' '<<c[l]<<' '<<r<<' '<<a[r]<<' '<<c[r]<<' '<<cnt<<endl;
		if(c[l]==c[r]){
			if(a[l]>a[r]){
				a[l]-=a[r];
				r--;
			}else if(a[l]<a[r]){
				a[r]-=a[l];
				l++;
			}else{
				l++;
				r--;
			}
		}else{
			if(a[l]>a[r]){
				a[l]-=a[r];
				cnt+=a[r];
				r--;
			}else if(a[l]<a[r]){
				a[r]-=a[l];
				cnt+=a[l];
				l++;
			}else{
				cnt+=a[l];
				l++;
				r--;
			}
		}
	}
	cout<<cnt<<endl;
	return 0;
}