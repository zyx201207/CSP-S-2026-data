#include<bits/stdc++.h>
#define int long long
#define N 200050
using namespace std;
char c[N];
int n,a[N],len,l,r,cnt,sum,ans;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for (int i=1; i<=n; i++){
		cin>>a[i]>>c[i];
		len+=a[i];
	}
	len>>=1; l=1; r=n;
	while (l<r && sum<len){
		if (sum+a[l]>len){
			a[l]=len-sum;
		}
		if (a[l]<a[r]){
			ans+=a[l]*(c[l]!=c[r]);
			sum+=a[l]; a[r]-=a[l++];
		} else if (a[l]>a[r]){
			ans+=a[r]*(c[l]!=c[r]);
			sum+=a[r]; a[l]-=a[r--];
		} else {
			ans+=a[l]*(c[l]!=c[r]);
			sum+=a[l]; l++; r--;
		}
	}
	cout<<ans;
	return 0;
}
