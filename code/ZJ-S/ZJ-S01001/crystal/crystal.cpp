#include <bits/stdc++.h>
using namespace std;
long long n,a[800009];
long long m,ans,num,k;
int main(){
	freopen("crystal.in","r",stdin);	
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=n;i>=1;i--){
		num=0;
		for(int j=1;j<i;j++){
			num+=(a[i]-a[i-j]);
		}
		if(num<=m){
			k=i;
			break;
		}
	}
	for(int i=k-1;i>=1;i--){
		if(m==0)break;
		if(a[k]-a[i]<=m && a[i]!=a[k]){
			m-=(a[k]-a[i]);
			a[i]=a[k];
		}
	}
	for(int i=1;i<=n;i++){
		if(a[i]==a[k]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
