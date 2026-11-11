#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,cnt=0;
int a[200005];
char c[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	int sum=0;
	for(int i=1;i<=n;i++){
		cin >> a[i] >> c[i];
		sum+=a[i];
	}
	int l=1,r=n;
	while(l<r){
		
		if(c[l]==c[r] ){
			if(a[l]>=a[r]){
				a[l]-=a[r];
				a[r]=0;
			}else {
				a[r]-=a[l];
				a[l]=0;
			}
		}else {
			if(a[l]>=a[r]){
				cnt+=a[r];
				a[l]-=a[r];
				a[r]=0;
			}else {
				cnt+=a[l];
				a[r]-=a[l];
				a[l]=0;
			}
		}
		while(a[l]<=0) l++;
		while(a[r]<=0) r--;
	}
	cout << cnt;
	return 0;
}
