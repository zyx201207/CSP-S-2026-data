#include<bits/stdc++.h>
using namespace std;
char c[210000];
long long n,ans,a[210000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	long long l=1,r=n;
	while(l<=r){
		if(a[l]==a[r]){
			if(c[l]==c[r]){
				l++;
				r--;
			}else{
				ans+=a[l];
				l++;
				r--;
			}
		}else if(a[l]<a[r]){
			if(c[l]==c[r]){
				a[r]-=a[l];
				l++;
			}else{
				ans+=a[l];
				a[r]-=a[l];
				l++;
			}
		}else{
			if(c[l]==c[r]){
				a[l]-=a[r];
				r--;
			}else{
				ans+=a[r];
				a[l]-=a[r];
				r--;
			}
		}
//		cout<<l<<" "<<a[l]<<" "<<r<<" "<<a[r]<<"\n";
	}
	cout<<ans<<"\n";
	return 0;
}
