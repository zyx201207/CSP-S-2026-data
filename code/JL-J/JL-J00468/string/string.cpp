#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[200005],f[200005],sum,ans;
char z[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>z[i];
	}
	for(int i=1,j=n;i<j;){
		if(a[i]<a[j]){
			if(z[i]!=z[j]) ans+=a[i];
			a[j]-=a[i];
			i++;
		}
		if(a[i]>a[j]){
			if(z[i]!=z[j]) ans+=a[j];
			a[i]-=a[j];
			j--;
		}
		if(a[i]==a[j]){
			if(z[i]!=z[j]) ans+=a[i];
			j--;
			i++;
		}
	}
	cout<<ans;
	return 0;
}
