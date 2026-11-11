#include<bits/stdc++.h>
using namespace std;
long long a[200005];
int n;
char a1[200005];
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>a[i]>>a1[i];
	}
	int cnt=n;
	long long ans=0;
	for(int i=1; i<=n; i++) {
		for(int j=cnt; j>i; j--) {
			if(a1[i]-'a'==a1[j]-'a') {
				if(a[i]>=a[j]) {
					a[i]=a[i]-a[j];
					a[j]=0;
					cnt--;
				} else {
					a[j]=a[j]-a[i];
					a[i]=0;
				}
			} else {
				if(a[i]>=a[j]) {

					a[i]=a[i]-a[j];
					ans=ans+a[j];
					a[cnt]=0;
					cnt--;
				} else {
					a[j]=a[j]-a[i];
					ans=ans+a[i];
					a[i]=0;
				}
			}
			if(a[i]==0) {
				break;
			}
		}
		if(cnt==i) {
			break;
		}
	}
	cout<<ans;
	return 0;
}