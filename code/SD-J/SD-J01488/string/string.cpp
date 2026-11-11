#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[200005],ans;
char b[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	int l=1,r=n;
	while(l<r){
		if(a[l]>a[r]){
			if(b[l]==b[r]){
				a[l]-=a[r];
				a[r]=0;
				r--;
			}else{
				a[l]-=a[r];
				ans+=a[r];
				a[r]=0;
				r--;
			}
		}else{
			if(b[l]==b[r]){
				a[r]-=a[l];
				a[l]=0;
				l++;
			}else{
				a[r]-=a[l];
				ans+=a[l];
				a[l]=0;
				l++;
			}
		}
	}
	cout<<ans;
	return 0;
}
