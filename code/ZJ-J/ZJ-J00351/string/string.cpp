#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	long long a[n+1];
	char c[n+1];
	for(int i=1; i<=n; i++) {
		cin>>a[i]>>c[i];
	}
	long long ans=0;
	long long l=1,r=n;
	while(1) {
//		cout<<ans<<" ";
//		cout<<l<<" "<<r<<" "<<a[r]<<" "<<c[r]<<" "<<a[l]<<" "<<c[l]<<endl;
		if(c[l]!=c[r]) {
			if(a[l]<a[r]) {
				ans+=a[l];
				a[r]-=a[l];
				l++;
			} else if(a[l]>a[r]) {
				ans+=a[r];
				a[l]-=a[r];
				r--;
			} else {
				ans+=a[l];
				r--;
				l++;
			}
		} else {
			if(a[l]<a[r]) {
				a[r]-=a[l];
				l++;
			} else if(a[l]>a[r]) {
				a[l]-=a[r];
				r--;
			} else {
				r--;
				l++;
			}
		}
		if(r<=l) break;
	}
	cout<<ans;
	return 0;
}
/*3
2 a
2 b
1 c
*/
/*
嵊州市新城实验学校909，ZHY LOVE ZZQ  
我的洛谷:yeweibo 
*/ 

