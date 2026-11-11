#include<bits/stdc++.h>
using namespace std;
long long n,a[210000],ans;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i]>>s[i];
	}
//	for(long long i=1;i<=n;i++){
//		cout<<a[i]<<' '<<s[i]<<endl;
//	}
	long long l=1,r=n;
	while(l<r){
		if(s[l]==s[r]){
			if(a[l]==a[r]){
				a[l]=0; a[r]=0;
				l++;r--;
			}
			else if(a[l]>a[r]){
				a[l]-=a[r]; a[r]=0;
				r--;
			}
			else {
				a[r]-=a[l]; a[l]=0;
				l++;
			}
		}
		else{
			if(a[l]==a[r]){
				ans+=a[l];
				a[l]=0; a[r]=0;
				l++;r--;
			}
			else if(a[l]>a[r]){
				ans+=a[r];
				a[l]-=a[r]; a[r]=0;
				r--;
			}
			else {
				ans+=a[l];
				a[r]-=a[l]; a[l]=0;
				l++;
			}
		}
	}
	cout<<ans;
	return 0;
}
