#include<bits/stdc++.h>
using namespace std;
int a[200005];
char b[200005];
int n,l,r;
long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	l=1;
	r=n;
	while(r>l){
		if(a[r]>a[l]){
			if(b[r]!=b[l]) ans+=a[l];
			a[r]-=a[l];
			l++;
		}
		if(a[r]<a[l]){
			if(b[r]!=b[l]) ans+=a[r];
			a[l]-=a[r];
			r--;
		}
		if(a[r]==a[l]){
			if(b[r]!=b[l]) ans+=a[l];
			l++;
			r--;
		}
	}
	cout<<ans;
	return 0;
}
