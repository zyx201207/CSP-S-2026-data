#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int m,n;
	cin>>n>>m;
	int a[10000];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int ans=0;
	if(m==1){
		for(int i=0;i<n;i++){
			ans=max(ans,a[i]);
		}
		cout<<ans;
		return 0;
	}
	if(m==2){
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
		return 0;
	}
	if(m==n){
		for(int i=0;i<n-1;i++){
			if(i==0){
				ans=a[i]&a[i+1];
			}
			ans=ans&a[i+1];
		}
		cout<<ans;
		return 0;
	}
	cout<<ans;
	return 0;
}
