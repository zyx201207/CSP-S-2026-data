#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=2e5+10;
int n,a[N],m,ans,l=1,r;
char c[N];
signed main(){
	ios::sync_with_stdio(0),cin.tie(),cout.tie();
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		m+=a[i];
	}
	r=n;
	while(l<r){
		if(c[l]!=c[r])ans+=min(a[l],a[r]);
		if(a[l]<a[r]){
			a[r]-=a[l];
			a[l]=0;
			l++;
		}else if(a[r]<a[l]){
			a[l]-=a[r];
			a[r]=0;
			r--;
		}else{
			a[l]=a[r]=0;
			l++;
			r--;
		}
	}
	cout<<ans;
	return 0;
}
