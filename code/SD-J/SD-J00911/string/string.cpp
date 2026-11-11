#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e5+5;
int a[maxn],n,ans;
char c[maxn];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin.tie(0)->sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int l=1,r=n;
	while(l<r){
		if(c[l]==c[r]){
			int k=(a[l]>a[r]?l:r),i=(k==l?r:l);
			a[k]-=a[i];
			if(i==l)l++;
			else r--;
		}
		else{
			int k=(a[l]>a[r]?l:r),i=(k==l?r:l);
			ans+=a[i];
			a[k]-=a[i];
			if(i==l)l++;
			else r--;
		}
	}
	cout<<ans;
	return 0;
}
//rp+=inf
