#include<bits/stdc++.h>
using namespace std;
long long n,m,z,a[500010],f=1,sum=0,ans=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	z=a[2]-a[1];
	for(int i=3;i<=n;i++){
		if(a[i]-a[i-1]!=z){
			f=0;
			break;
		}
	}
	if(f==1){
		ans=1;
		for(int i=1;i<n;i++){
			if((i*(i-1)/2)*z<=m)ans=i+1;
			else break;
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n-ans;i++){
		sum=1;
		z=m;
		for(int j=i;j<n;j++){
			if((a[j+1]-a[j])*(j-i+1)<=m){
				sum++;
				m-=(a[j+1]-a[j])*(j-i+1);
			}else break;
		}
		ans=max(ans,sum);
		m=z;
	}
	cout<<ans;
	return 0;
}