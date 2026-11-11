#include<bits/stdc++.h>
using namespace std;
long long n,a[200009],l,r,ans;
string s[200009];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
	}
	l=1;
	r=n;
	while(l<r){
		if(s[l]==s[r]){
			if(a[l]>a[r]){
				a[l]-=a[r];
				a[r]-=a[r];
				r--;
				continue;
			}
			if(a[l]==a[r]){
				a[l]=0;
				a[r]=0;
				l++,r--;
				continue;
			}
			if(a[l]<a[r]){
				a[r]-=a[l];
				a[l]-=a[l];
				l++;
				continue;
			}
		}
		if(a[l]>a[r]){
			ans+=a[r];
			a[l]-=a[r];
			a[r]-=a[r];
			r--;
			continue;
		}
		if(a[l]==a[r]){
			ans+=a[r];
			a[l]=0;
			a[r]=0;
			l++,r--;
			continue;
		}
		if(a[l]<a[r]){
			ans+=a[l];
			a[r]-=a[l];
			a[l]-=a[l];
			l++;
			continue;
		}
	}
	cout<<ans;
}
