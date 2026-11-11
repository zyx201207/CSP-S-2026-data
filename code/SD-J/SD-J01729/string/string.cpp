#include<bits/stdc++.h>
using namespace std;
char al[5000001],s,as[5000001],c[200005];
long long n,m,ls,ans,l,r,po,a[200005];
int main(){
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		po=max(po,a[i]);		
	}
	if(po*n<=5e6){
		for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			al[++m]=c[i];	
		}
	}
		for(int i=m;i>=1;i--){
		as[i]=al[++l];
	}
	for(int i=1;i<=(m+1)/2;i++){
		if(as[i]!=al[i]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
	}
	l=1;r=n;
	while(l<r){
		if(c[l]==c[r]){
			if(a[l]==a[r]){
				continue;
				l++;r--;
			}else if(a[l]>a[r]){
				a[l]-=a[r];
				r--;
				continue;
			}else{
				a[r]-=a[l];
				l++;
				continue;
			}
		}else{
			if(a[l]==a[r]){
				ans+=a[l];
				l++;r--;
				continue;
			}else if(a[l]>a[r]){
				ans+=a[r];
				a[l]-=a[r];r--;
				continue;
			}else{
				ans+=a[l];
				a[r]-=a[l];l++;
			}
		}
	}
	cout<<ans;
	return 0;
}
