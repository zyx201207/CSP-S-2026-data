#include<bits/stdc++.h>
using namespace std;
int m,n,a[200005],cnt;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		int ans=-1;
		for(int i=1;i<=n;i++){
			ans=max(ans,a[i]);
		}
		cout<<ans;
		return 0;
	}
	if(m==2){
		int ans=-1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j)continue;
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
		return 0;
	}
	if(m==n){
		int ans=a[1];
		for(int i=2;i<=n;i++){
			ans=ans&a[i];
		}
		cout<<ans;
		return 0;
	}
	if(m==n-1){
		int ans=a[2];
		for(int i=3;i<=n;i++){
			ans=ans&a[i];
		}
		
		int cur=ans;
		for(int i=2;i<=n;i++){
			ans=a[1];
			for(int j=1;j<=n;j++){
				if(i==j)break;
				ans=ans&a[j];
			}
			cur=max(ans,cur);
		} 
		cout<<ans;
		return 0;
	} 
	
	return 0;
} 
