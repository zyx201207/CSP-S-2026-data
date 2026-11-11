#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[200010],ans,l,r;
char s[200010];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
	}
	l=1;
	r=n;
	while(l<=r){
		if(a[l]>a[r]){
			if(s[l]!=s[r]) ans+=a[r];
			a[l]-=a[r];
			r--;
		}
		if(a[l]<a[r]){
			if(s[l]!=s[r]) ans+=a[l];
			a[r]-=a[l];
			l++;
		}
		if(a[l]==a[r]){
			if(s[l]!=s[r]) ans+=a[l];
			l++;
			r--;
		}
	}
	cout<<ans;
	return 0; 
}
