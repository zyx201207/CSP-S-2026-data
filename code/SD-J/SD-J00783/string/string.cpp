#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int n,a[N],len,l,r,cnt,cnta;
char c[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		len+=a[i];
	}
	l=1;
	r=n;
	while(l<=r){
		if(a[l]==0){
			l++;
		}
		if(a[r]==0){
			r--;
		}
		if(c[l]==c[r]){
			if(a[l]>a[r]){
				cnta+=a[r];
				a[l]-=a[r];
				a[r]=0;
				r--;
			}else if(a[l]<a[r]){
				cnta+=a[l];
				a[r]-=a[l];
				a[l]=0;
				l++;
			}else{
				cnta+=a[l];
				a[l]=0;
				a[r]=0;
				l++;
				r--;
			}
		}else{
			if(a[l]>a[r]){
				cnta+=a[r];
				cnt+=a[r];
				a[l]-=a[r];
				a[r]=0;
				r--;
			}else if(a[l]<a[r]){
				cnta+=a[l];
				cnt+=a[l];
				a[r]-=a[l];
				a[l]=0;
				l++;
			}else{
				cnta+=a[l];
				cnt+=a[l];
				a[l]=0;
				a[r]=0;
				l++;
				r--;
			}
		}
		if(cnta>=len/2){
			break;
		}
	}
	cout<<cnt;
	return 0;
}
