#include<bits/stdc++.h> 
using namespace std;
long long n,m,ans;
long long a[200005];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	if(m==1){
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		sort(a,a+1+n,cmp);
		cout<<a[1];
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++)
			ans=max(ans,a[i]&a[j]);
		}
		cout<<ans;
		return 0;	
	}
	if(m==3&&n<=20){
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					ans=max(ans,a[i]&a[j]&a[k]);	
				}
			}
		}
		cout<<ans;
		return 0;	
	}
	if(m==4&&n<=20){
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int o=k+1;o<=n;o++){
						ans=max(ans,a[i]&a[j]&a[k]&a[o]);	
					}	
				}
			}
		}
		cout<<ans;
		return 0;	
	}
	if(m==5&&n<=20){
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int o=k+1;o<=n;o++){
						for(int p=o+1;p<=n;p++){
						ans=max(ans,a[i]&a[j]&a[k]&a[o]&a[p]);	
						}	
					}	
				}
			}
		}
		cout<<ans;
		return 0;	
	}
	if(m==6&&n<=20){
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int o=k+1;o<=n;o++){
						for(int p=o+1;p<=n;p++){
							for(int q=p+1;q<=n;q++)
							ans=max(ans,a[i]&a[j]&a[k]&a[o]&a[p]&a[q]);	
						}	
					}	
				}
			}
		}
		cout<<ans;
		return 0;	
	}
	if(m==7&&n<=20){
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int o=k+1;o<=n;o++){
						for(int p=o+1;p<=n;p++){
							for(int q=p+1;q<=n;q++){
								for(int e=q+1;e<=n;e++)
								ans=max(ans,a[i]&a[j]&a[k]&a[o]&a[p]&a[q]&a[e]);
							}	
						}	
					}	
				}
			}
		}
		cout<<ans;
		return 0;	
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a,a+1+n,cmp);
	ans=a[1];
	for(int i=2;i<=m;i++){
		ans=ans&a[i];
	}
	cout<<ans;
}
