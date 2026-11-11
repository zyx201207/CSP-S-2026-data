#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,sum,ans,a[200005];
char c[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i = 1;i<=n;i++){
		cin>>a[i]>>c[i];
		sum += a[i];
	}
	int l = 0,r = n,L = 0,R = a[r];
	while(l < r-1){
		if(L <= R){
			l++;
			if(c[l] != c[r]){
				ans += min(R-L,a[l]);
			}
			L += a[l];
		}else{
			r--;
			if(c[l] != c[r]){
				ans += min(L-R,a[r]);
			}
			R += a[r];
		}
	}
	cout<<ans;
	return 0;
}