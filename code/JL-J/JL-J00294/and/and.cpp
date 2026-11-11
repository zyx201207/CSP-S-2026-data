#include<bits/stdc++.h>
using namespace std;
long long a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==n){
		int ans=0;
		for(int i=1;i<=n;i++) ans=ans&a[i];
		cout<<ans<<endl;
		return 0;
	}
	if(m==1){
		int ans=0;
		for(int i=1;i<=n;i++){
			if(ans<a[i]) ans=a[i];
		}
		cout<<ans<<endl;
		return 0;
	}
	if(m==2){
		int ans=0;
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[i]&a[j]>ans) ans=a[i]&a[j];
			}
		}
		cout<<ans<<endl;
		return 0;
	}
	if(m==n-1){
		int ans=0,sum=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(j==i) continue;
				sum=sum&a[j];
			}
			if(sum>ans) ans=sum;
		}
		cout<<ans<<endl;
		return 0;
	}
	if(m==3){
		int ans=0;
		for(int i=1;i<=n-2;i++){
			for(int j=i+1;j<n;j++){
				for(int k=i+2;k<=n;k++){
					if(a[i]&a[j]&a[k]>ans) ans=a[i]&a[j]&a[k];
				}
			}
		}
		cout<<ans<<endl;
		return 0;
	}
	return 0;
}
