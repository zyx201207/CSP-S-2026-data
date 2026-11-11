#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],ans,l=1,r;
char b[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	r=n;
	while(l<r){
		if(b[l]!=b[r]) ans+=min(a[l],a[r]);
		if(a[l]>a[r]){
			a[l]-=a[r];r--;
		}else if(a[l]<a[r]){
			a[r]-=a[l];l++;
		}else{
			l++;r--;
		}
	}
	cout<<ans;
	return 0;
}
