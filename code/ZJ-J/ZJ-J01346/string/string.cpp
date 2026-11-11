#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
char c[200100];
int a[200100];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int l=1,r=n,res=0;
	while(l<r){
		if(a[l]==a[r]){
			if(c[l]!=c[r])res+=a[l];
			l++;
			r--;
		}
		if(a[l]>a[r]){
			if(c[l]!=c[r])res+=min(a[l],a[r]);
			a[l]-=a[r];
			r--;
		}
		if(a[l]<a[r]){
			if(c[l]!=c[r])res+=min(a[l],a[r]);
			a[r]-=a[l];
			l++;
		}
	}
	cout<<res;
	return 0;
} 
