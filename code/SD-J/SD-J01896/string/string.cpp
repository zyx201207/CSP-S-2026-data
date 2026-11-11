#include <bits/stdc++.h>
using namespace std;
long long n,a[200005],sum[200005],ans,pos;
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sum[i]=sum[i-1]+a[i];
		
		
	}
	for(int i=1;i<=n;i++){
		if(sum[i]>=sum[n]/2){
			pos=i;
			break;
		}
	}
	for(int i=1;i<=pos;i++){
		if(c[i]!=c[n-i+1]){
			ans+=min(a[i],a[n-i+1]);
			if(a[i]>a[n-i+1]){
				a[i]=a[i]-a[n-i+1];
				i--;
			}
			if(a[i]<a[n-i+1]){
				a[n-i+1]-=a[i];
				i--;
			}
		}
	}
	cout<<ans;
	return 0;
}
