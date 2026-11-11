#include<bits/stdc++.h>
using namespace std;
int n,m;
long long ans=pow(2,40)-1;
long long a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(a[n-m+1]==0) ans=0;
	if(m==1) ans=a[n];
	if(m==2){
		ans=0;
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
	}
	if(m==n){
		for(int i=1;i<=n;i++){
			ans=ans&a[i];
		}
	}
	bool flag=1;
	for(int i=n-m+1;i<=n;i++){
		if(a[i]|ans!=a[i]){
			flag=0;
			break;
		}
	}
	if(flag==1) ans=a[n-m+1];
	cout<<ans;
	return 0;
}
