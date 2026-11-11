#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	if(m==1){
		int ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(a[i]>ans){
				ans=a[i];
			}
		}
		cout<<ans;
		return 0;
	}
	else if(m==n){
		int ans=0;
		cin>>a[1];
		ans=a[1];
		for(int i=2;i<=n;i++){
			cin>>a[i];
			ans=ans&a[i];
		}
		cout<<ans;
		return 0;
	}
	else if(m==2){
		int ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				if(j==i){
				  continue;
				}
				if(a[i]&a[j]>ans){
			  	  ans=a[i]&a[j];
				}
			}
		}
		cout<<ans;
		return 0;
	}
	int ans=0;
	for(int i=1;i<=n-m+1;i++){
		int x=a[i];
		for(int j=i+1;j<=j+m-1;j++){
			x=x&a[j];
		}
		if(x>ans){
			ans=x;
		}
	}
	cout<<ans;
	return 0;
}
