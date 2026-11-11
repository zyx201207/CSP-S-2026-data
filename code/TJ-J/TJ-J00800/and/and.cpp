#include<bits/stdc++.h>
using namespace std; 
int a[200010],ans,n,flag[20010],maxx;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int m;
	cin>>n>>m;
	if(m==1){
		for(int i=1;i<=n;i++){
			cin>>a[i];
			ans=max(ans,a[i]);
		}
		cout<<ans;
	}
	else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(j!=i){
					ans=max(ans,a[i]&a[j]);
				}
			}
		}
		cout<<ans;
	}
	else if(m==n){
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		ans=a[1];
		for(int i=2;i<=n;i++){
			ans&=a[i];
		}
		cout<<ans;
	}
	else{
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(a[n]=n-1) cout<<n-1;
		else{
			sort(a+1,a+n+1);
			cout<<a[m];
		}
	}
	return 0;
} 
