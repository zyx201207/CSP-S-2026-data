#include<bits/stdc++.h>
#define int long long
using namespace std;
char b[200010];
int n,i,l,r,ans,a[200010];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(i=1;i<=n;i++) cin>>a[i]>>b[i];
	l=1,r=n;
	while(l<=r){
		if(a[l]==a[r]){
			if(b[l]!=b[r]) ans+=a[l];
			a[l]=a[r]=0;
			l++,r--;
		}
		else{
			if(a[l]<a[r]){
				if(b[l]!=b[r]) ans+=a[l];
				a[r]-=a[l],a[l]=0;
				l++;
			}
			else{
				if(b[l]!=b[r]) ans+=a[r];
				a[l]-=a[r],a[r]=0;
				r--;
			}
		}
	}
	cout<<ans;
}
