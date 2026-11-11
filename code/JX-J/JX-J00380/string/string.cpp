#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],l,r,ans;
char b[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	l=1,r=n;
	while(l<r){
		if(b[l]==b[r]){
			if(a[l]<a[r]){
				a[r]-=a[l];
				l++;
			}else if(a[l]>a[r]){
				a[l]-=a[r];
				r--;
			}else {
				l++,r--;
			}
		}else{
			if(a[l]<a[r]){
				ans+=a[l];
				a[r]-=a[l];
				l++;
			}else if(a[l]>a[r]){
				ans+=a[r];
				a[l]-=a[r];
				r--;
			}else {
				ans+=a[l];
				l++,r--;
			}
		}
	}
	cout<<ans;
	return 0;
}
