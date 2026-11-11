#include<bits/stdc++.h>
using namespace std;
int n,m;
long long ans,a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==n){
		ans=a[1];
		for(int i=2;i<=n;i++){
			ans=ans&a[i];
		}
		cout<<ans;
		return 0;
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			ans=max(ans,a[i]);
		}
		cout<<ans;
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j) continue;
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
		return 0;
	}
	if(m==3){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				for(int k=1;k<=n;k++){
					if(i==j || i==k || j==k) continue;
					ans=max(ans,a[i]&a[j]&a[k]);
				}
			}
		}
		cout<<ans;
		return 0;
	}
	
	if(m==4){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				for(int k=1;k<=n;k++){
					for(int h=1;h<=n;h++){
						if(i==j || i==k || j==k || i==h || j==h || k==h) continue;
						ans=max(ans,a[i]&a[j]&a[k]&a[h]);
					}
				}
			}
		}
		cout<<ans;
		return 0;
	}
	
	if(m==5){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				for(int k=1;k<=n;k++){
					for(int h=1;h<=n;h++){
						for(int o=1;o<=n;o++){
							if(i==j || i==k || j==k || i==h || j==h || k==h || o==i || o==j ||o==k ||o==h) continue;
							ans=max(ans,a[i]&a[j]&a[k]&a[h]&a[o]);
						}
					}
				}
			}
		}
		cout<<ans;
		return 0;
	}
	
	if(m==6){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				for(int k=1;k<=n;k++){
					for(int h=1;h<=n;h++){
						for(int o=1;o<=n;o++){
							for(int q=1;q<=n;q++){
								if(i==j || i==k || j==k || i==h || j==h || k==h || o==i || o==j ||o==k ||o==h || q==i || q==j ||q==k ||q==o||q==h) continue;
								ans=max(ans,a[i]&a[j]&a[k]&a[h]&a[o]&a[q]);
							}
						}
					}
				}
			}
		}
		cout<<ans;
		return 0;
	}
	
	if(m==7){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				for(int k=1;k<=n;k++){
					for(int h=1;h<=n;h++){
						for(int o=1;o<=n;o++){
							for(int q=1;q<=n;q++){
								for(int v=1;v<=n;v++){
									if(i==j || i==k || j==k || i==h || j==h || k==h || o==i || o==j ||o==k ||o==h || q==i || q==j ||q==k ||q==o||q==h||v==i|| v==j||v==k ||v==h || v==o||v==q) continue;
									ans=max(ans,a[i]&a[j]&a[k]&a[h]&a[o]&a[q]&a[v]);
								}
							}
						}
					}
				}
			}
		}
		cout<<ans;
		return 0;
	}
	return 0;
} 

