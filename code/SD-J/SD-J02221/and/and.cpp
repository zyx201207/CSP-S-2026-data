#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m;
ll ans,a[200005],sum;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum=max(a[i],sum);
	}
	if(m==1)ans=sum;
	else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=min(ans,a[i]&a[j]);
			}
		}
	}
	else if(m==3){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int x=j+1;x<=n;x++){
					ans=min(ans,a[i]&a[j]);
				}
				
			}
		}
	}
	else if(m==4){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int x=j+1;x<=n;x++){
					for(int y=x+1;y<=n;y++){
					ans=min(ans,a[i]&a[j]);
				}
				}
				
			}
		}
	}
	else if(m==5){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int x=j+1;x<=n;x++){
					for(int y=x+1;y<=n;y++){
					for(int o=y+1;o<=n;o++){
					ans=min(ans,a[i]&a[j]);
				}
				}
				}
				
			}
		}
	}
	else if(m==n){
		for(int i=1;i<=n;i++){
			ans=ans&a[i];
		}
	}
	else{
		sort(a+1,a+1+n);
		for(int i=1;i<=m;i++)ans=ans&a[i];
	}
	cout<<ans;
	return 0;
}
//Trick||Treat!

