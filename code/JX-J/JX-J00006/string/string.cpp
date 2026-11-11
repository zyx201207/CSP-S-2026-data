#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a[200002];
	char c[200002];
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	long long ans=0;
	int l=1,r=n;
	while(l<r){
		if(c[l]!=c[r]) ans+=min(a[l],a[r]);
		if(a[l]<a[r]){
			a[r]-=a[l];
			l++;
		} else if(a[l]==a[r]){
			l++;
			r--;
		} else {
			a[l]-=a[r];
			r--;
		}
	}
	cout<<ans;
	return 0;
}
