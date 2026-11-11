#include <bits/stdc++.h>
using namespace std;
int ans;
int a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n,m;
	cin>>n>>m;
	
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(m==n){
		ans=a[0];
		for(int i=1;i<n;i++){
			ans=a[i]&ans;
		}
		cout<<ans;
	}
	else if(m==1){
		for(int i=0;i<n;i++){
			if(a[i]>ans) ans=a[i];
		}
		cout<<ans;
	}
	else if(m==2){
		for(int i=0;i<n-1;i++){
			for(int j=i+1;j<n;j++){
				if(a[i]&a[j]>ans) ans=a[i]&a[j];
			} 
		}
		cout<<ans;
	} 
	else if(m==3){
		for(int i=0;i<n-2;i++){
			for(int j=i+1;j<n-1;j++){
				for(int k=j+1;k<n;k++)
				if((a[i]&a[j])&a[k]>ans) ans=(a[i]&a[j])&a[k];
			} 
		}
		cout<<ans;
	}
	else if(m==n-1&&m!=2&&m!=1&&m!=3){
		int ans2;
		for(int i=0;i<n;i++){
			ans=1;
			for(int j=0;j<n;j++){
				if(j==i) continue;
				else{
					ans=ans&a[j];
				}
				
			}
			if(ans>ans2) ans2=ans;
		}
		cout<<ans2;
	}
	return 0;
}
