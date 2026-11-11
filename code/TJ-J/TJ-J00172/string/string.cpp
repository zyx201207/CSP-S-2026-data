#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,ans,a[200005];
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]>>c[i];
	ll l=1,r=n;
	while(l<r){
		if(c[l]==c[r]){
			if(a[l]>a[r]){
				a[l]-=a[r];
				r--;
			}
			else if(a[l]==a[r])l++,r--;
			else {
				a[r]-=a[l];
				l++;
			}
		}else{
			if(a[l]>a[r]){
				ans+=a[r];
				a[l]=a[l]-a[r];
				r--;
			}else if(a[l]==a[r]){
				ans+=a[l];
				l++;
				r--;
			}else{
				ans+=a[l];
				a[r]-=a[l];
				l++;
			}
//			cout<<l<<' '<<r<<' '<<ans<<endl;
		}
	}
	cout<<ans;
	return 0;
}
