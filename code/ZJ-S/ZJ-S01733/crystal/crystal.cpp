#include<bits/stdc++.h>
#define endl '\n'
#define int int64_t
using namespace std;
int n,m,a[500010],qz[500010],ans;
int binary_find(int x){
	int l=x,r=n,mid,ans;
	while(l<=r){
		mid=l+r>>1;
//		cout<<mid<<' '<<a[mid]*(mid-x)-qz[mid-1]-qz[x-1]<<endl;
		if(a[mid]*(mid-x)-(qz[mid-1]-qz[x-1])<=m){
			ans=mid;
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	return ans;
}
int32_t main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		qz[i]=qz[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
//		cout<<i<<":\n";
		ans=max(ans,binary_find(i)-i+1);
	}
	cout<<ans<<endl;
	return 0;
}

