#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[500005];
int mx;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i)b[i]=b[i-1]+a[i];
	for(int i=n;i>=1;--i){
		int l=1,r=i;
		while(l+10<=r){
			int mid=(l+r)>>1;
			if((i-mid)*a[i]-(b[i-1]-b[mid-1])<=m){
				r=mid;
			}else{
				l=mid-1;
			}
		}
		for(int j=l;j<=r;++j){
			if((i-j)*a[i]-(b[i-1]-b[j-1])<=m){
				mx=max(mx,i-j+1);
			}
		}
	}
	cout<<mx;
	return 0;
}

