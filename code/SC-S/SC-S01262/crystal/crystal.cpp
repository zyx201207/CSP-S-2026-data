#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],c[500005];
int tot[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i){
		c[i]=a[i]-a[i-1];
	}
	for(int i=2;i<=n;++i){
		tot[i]=tot[i-1]+(i-1)*c[i];
	}
	int maxn=1;
	for(int l=1;l<=n;++l){
		int left=l+1,right=n;
		while(left<right){
			int mid=(left+right+1)/2;
			if(tot[mid]-tot[l]-(l-1)*(a[mid]-a[l+1])>m){
				right=mid-1;
			}else{
				left=mid;
			}
		}
		maxn=max(maxn,right-l+1);
	}
	cout<<maxn;
	return 0;
}
