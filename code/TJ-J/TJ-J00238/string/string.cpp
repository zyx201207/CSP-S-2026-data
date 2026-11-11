#include<bits/stdc++.h>

using namespace std;
#define int long long
int n,l=1,r,a[200005],ans;
char s[200005] ;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	r=n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
	}
	while(l<r){
		if(s[l]==s[r]){
			if(a[l]>a[r]){
				a[l]-=a[r];
				r--;
			}else if(a[l]<a[r]){
				a[r]-=a[l];
				l++;
			}else{
				l++;
				r--;
			}
		}else{
			if(a[l]>a[r]){
				ans+=a[r];
				a[l]-=a[r];
				r--; 
			}else if(a[l]<a[r]){
				ans+=a[l];
				a[r]-=a[l];
				l++;
			}else{
				ans+=a[l];
				l++;
				r--;
			}
		}
	}
	cout<<ans;
	return 0;
}
