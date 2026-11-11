#include<bits/stdc++.h>
using namespace std;
char s[200005];
long long n,a[200005];
long long l=1,r,diff;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i]>>s[i];
	}
	l=1,r=n;
	while(l<r){
		if(s[l]!=s[r]){
			if(a[l]<a[r]){
				s[r]=s[l];
				diff+=a[l];
			}else{
				s[l]=s[r];
				diff+=a[r];
			}
		}
		long long d=min(a[l],a[r]);
		a[l]-=d;
		a[r]-=d;
		if(a[l]==0)l++;
		if(a[r]==0)r--;
	}
	cout<<diff;
	return 0;
}
//expected 100pts      5/5
