#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5e5+5;
int n,m,a[maxn],ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	if (n<=5000){
		for (int i=1;i<=n;i++){
			int sum=0,xb=0;
			for (int j=i;j>=1;j--){
				sum+=a[i]-a[j];
				if (sum>m){
					xb=j+1;break;
				}
			}
			if (xb==0) ans=max(ans,i);
			else ans=max(ans,i-xb+1);
		}
		cout<<ans;
	}
	else {
		int ox=a[2]-a[1],bjb=0;
		for (int i=1;i<=n;i++){
			if (i*(i-1)/2*ox>m){
				bjb=i-1;break;
			}
		}
		cout<<bjb;
	}
	return 0;
}
