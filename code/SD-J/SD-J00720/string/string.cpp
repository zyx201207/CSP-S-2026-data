#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int n,a[210000],ans;
string b[210000];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	int l=1,r=n;
	while(l<=r){
		if(b[l]!=b[r]){
			if(a[l]>a[r]){
				ans+=a[r];
				a[l]=a[l]-a[r];
				r--;
			}else{
				ans+=a[l];
				a[r]=a[r]-a[l];
				l++;
			}
		}else{
			if(a[l]>a[r]){
				a[l]=a[l]-a[r];
				r--;
			}else{
				a[r]=a[r]-a[l];
				l++;
			}
		}
//		cout<<l<<" "<<r<<" "<<ans<<endl;
	}
	cout<<ans<<endl;
	return 0;
}

