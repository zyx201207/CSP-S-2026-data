#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500007],pr[500007];
int n,m;
int bin_search(int i){
	int l=1,r=i;
	while(l<r){
		int mid=(l+r+1)>>1;
		if(a[i]*mid-pr[i]+pr[i-mid]==m)return mid;
		if(a[i]*mid-pr[i]+pr[i-mid]<m){
			l=mid;
		}else{
			r=mid-1;
		}
	}
	return l;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		pr[i]=a[i]+pr[i-1];
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		ans=max(ans,bin_search(i));
	}
	cout<<ans;
	return 0;
}//a[i]*mid-pr[i]+pr[i-mid]

