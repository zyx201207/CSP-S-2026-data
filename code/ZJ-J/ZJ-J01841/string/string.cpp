#include<bits/stdc++.h>
using namespace std;
int a[100000009];char c[100000009];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;long long ans=0;cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
	}int l=0,r=n-1;
	while(l<=r){
		if(a[l]>a[r]){
			ans+=(c[l]==c[r]?0:a[r]);
			a[l]-=a[r];
			r--;
		}else if(a[l]<a[r]){
			ans+=(c[l]==c[r]?0:a[l]);
			a[r]-=a[l];
			l++;
		}else{
			ans+=(c[l]==c[r]?0:a[r]);
			l++;r--;
		}
	}
	cout<<ans<<endl;
	return 0;
}