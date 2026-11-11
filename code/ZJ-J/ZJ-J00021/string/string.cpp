#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[200005];
char c[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cin>>c[i];
	}
	int l=1,r=n,sum=0;
	while(l<r){
		if(a[l]==a[r]){
			if(c[l]!=c[r]) sum+=a[l];
			++l,--r;
		}
		else if(a[l]>a[r]){
			if(c[l]!=c[r]) sum+=a[r];
			a[l]-=a[r];
			--r;
		}
		else{
			if(c[l]!=c[r]) sum+=a[l];
			a[r]-=a[l];
			++l;
		}
	}
	cout<<sum;
	return 0;
}
