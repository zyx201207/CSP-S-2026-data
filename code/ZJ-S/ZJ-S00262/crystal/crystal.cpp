#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,a[N],f[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		f[i]=f[i-1]+a[i];
	}
	int l=1,r=n;
	while(l<r){
		int mid=(l+r+1)/2,ans=m+1;//mid->answer
		for(int i=1;i<=n-mid+1;i++){
			ans=min(ans,mid*a[i+mid-1]-f[i+mid-1]+f[i-1]);
		}
		if(ans==m+1) r=mid-1;
		else if(ans<=m) l=mid;
	}
	cout<<l;
	return 0;
}