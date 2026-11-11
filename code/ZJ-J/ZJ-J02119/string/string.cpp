#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[200009],n,ans;
char s[200009];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>s[i];
	for(int l=1,r=n;l<r;){
		while(a[l]){
			if(s[r]==s[l]){
				if(a[r]>a[l]){
					a[r]-=a[l];
					a[l]=0;
					l++;
				}else if(a[l]>a[r]){
					a[l]-=a[r];
					a[r]=0;
					r--;
				}else{
					a[r]=0;
					a[l]=0;
					l++;
					r--;
				}
			}else{
				if(a[r]>a[l]){
					ans+=a[l];
					a[r]-=a[l];
					a[l]=0;
					l++;
				}else if(a[l]>a[r]){
					ans+=a[r];
					a[l]-=a[r];
					a[r]=0;
					r--;
				}else{
					ans+=a[l];
					a[r]=0;
					a[l]=0;
					l++;
					r--;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
