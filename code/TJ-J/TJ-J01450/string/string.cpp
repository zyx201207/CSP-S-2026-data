#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,ans=0;
	cin>>n;
	int a[n+1];
	char c[n+1];
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int r=n,l=1;
	while(l<r){
		if(c[l]==c[r]){
			if(a[l]>a[r]){
				a[l]-=a[r];
				r--;
			}else if(a[r]>a[l]){
				a[r]-=a[l];
				l++;
			}else{
				l++;
				r--;;
			}
		}else{
			if(a[r]>a[l]){
				ans+=a[l];
				a[r]-=a[l];
				l++;
			}else if(a[l]>a[r]){
				ans+=a[r];
				a[l]-=a[r];
				r--;
			}else{
				ans+=a[r];
				r--;
				l++;
			}
		}
	}
	cout<<ans;
	return 0;
}
