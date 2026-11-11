#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long a[N];
int n,m;
long long maxx=0,ans;
void dfs(int cnt,int k,long long ans){
	long long max1=0;
	for(int i=k+1;i<=n;i++){
		max1=max(max1,ans&a[i]);
	}
	ans=max1;
	if(cnt==m){
		maxx= max(maxx,ans);
		return;
	}
	dfs(cnt+1,k+1,ans);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			maxx=max(maxx,a[i]);
		}
		cout<<maxx;
	}else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				maxx=max(maxx,a[i]&a[j]);
			}
		}
		cout<<maxx;
	}else if(m==n){
		ans=a[1];
		for(int i=1;i<n;i++){
			ans=ans&a[i+1];
		}
		cout<<ans;
	}else{
		if(m==3){
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					for(int k=j+1;k<=n;k++){
						maxx=max(maxx,a[i]&a[j]&a[k]);
					}
				}
			}
			cout<<maxx;
		}else if(m==4){
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					for(int k=j+1;k<=n;k++){
						for(int l=k+1;l<=n;l++){
							maxx=max(maxx,a[i]&a[j]&a[k]&a[l]);
						}
					}
				}
			}
		}else if(m==5){
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					for(int k=j+1;k<=n;k++){
						for(int l=k+1;l<=n;l++){
							for(int r=l+1;r<=n;r++){
								maxx=max(maxx,a[i]&a[j]&a[k]&a[l]&a[r]);
							}
						}
					}
				}
			}
		}else if(m==6){
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					for(int k=j+1;k<=n;k++){
						for(int l=k+1;l<=n;l++){
							for(int r=l+1;r<=n;r++){
								for(int e=r+1;e<=n;e++){
									maxx=max(maxx,a[i]&a[j]&a[k]&a[l]&a[r]&a[e]);
								}
							}
						}
					}
				}
			}
		}
		else{
			dfs(1,0,a[1]);
			cout<<maxx;
		}
		
	}
	return 0;
}
