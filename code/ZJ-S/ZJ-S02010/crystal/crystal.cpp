#include<bits/stdc++.h>
using namespace std;
long long n,m,l,r,mid,s,a[500005],b[500005],f[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;s=1;
	for (int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for (int i=2;i<=n;i++) b[i]=a[i]-a[1];
	for (int i=2;i<=n;i++) f[i]=f[i-1]+(a[i]-a[i-1])*i;
	for (int i=1;i<=n;i++){
		l=i+1;r=n;
		while (l<=r){
			mid=(l+r)/2;
			if (f[mid]-f[i]-b[mid]*i+b[i]*i<=m){
				l=mid+1;
				s=max(s,mid-i+1);
			}else r=mid-1;
		}
	}cout<<s;
}
