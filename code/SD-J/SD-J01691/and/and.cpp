#include <bits/stdc++.h>
using namespace std;
int n,m,a[2200],ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(m==1){
		cout<<a[n];
	}
	if(m==1){
		ans=a[1];
		for(int i=2;i<=n;i++){
			ans=(ans|a[i]);
		}
		cout<<ans;
	}
	if(m>2){
		ans=(a[n]|a[n-1]);
		cout<<ans; 
	}
	if(m==2){
		ans=-1;
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,a[i]|a[j]);
			}
		}
		cout<<ans;
	}
	return 0;
} 
