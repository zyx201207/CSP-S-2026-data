#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],f[500005],b[500005],ans,s[500005];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	f[1]=0;
	for(int i=2;i<=n;i++){
		f[i]=a[i]-a[i-1];
		s[i]=s[i-1]+a[i];
	}
	for(int i=2;i<=n;i++){
		b[i]=b[i-1]+f[i]*(i-1);
	}
	for(int i=1;i<=n;i++){
		if(b[i]<=m){
			ans=max(ans,i);
		}else{
			int l=1,r=i-1,mid;
			while(l<=r){
				mid=(l+r)/2;
				int d=b[i]-(a[i]*mid-s[mid]);
				if(d>=m){
					l=mid+1;
				}else{
					r=mid-1;
				}
			}
			ans=max(ans,i-r);
		}
	}
	cout<<ans;
	return 0;
}
