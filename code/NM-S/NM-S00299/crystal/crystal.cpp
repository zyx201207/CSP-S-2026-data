#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,m,a[1001010],res;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(LL i=1;i<=n;i++){
		LL t=1;
		for(int j=n;j>=1;j--){
			if(a[j]<=a[i] && m>=a[i]-a[j]) {
				m=m-(a[i]-a[j]);
				t++;
			}
			if(a[j]>a[i]) continue;
			if(a[j]<=a[i] && m<a[i]-a[j]) break;
		}
		res=max(res,t);
	} 
	cout<<res;
	return 0;
} 
