#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
const int N=2e5+5;
ll maxx=-inf;
int m,n;
int a[N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(1LL*a[i],maxx);
	}
	if(m==1){
		cout<<maxx;
	}
	if(m==2){
		maxx=-inf;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				maxx=max(maxx,(a[i]&a[j])*1LL);
			}
		}
		cout<<maxx;
		return 0;
	}
	if(m==3){
		maxx=-inf;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					maxx=max(maxx,(a[i]&a[j]&a[k])*1LL);
				}
			}
		}
		cout<<maxx;
		return 0;
	}
	if(m==4){
		maxx=-inf;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						maxx=max(maxx,(a[i]&a[j]&a[k]&a[l])*1LL);
					}
				}
			}
		}
		cout<<maxx;
		return 0;
	}
	if(m==5){
		maxx=-inf;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int m=l+1;m<=n;m++){
							maxx=max(maxx,(a[i]&a[j]&a[k]&a[l]&a[m])*1LL);
						}
					}
				}
			}
		}
		cout<<maxx;
		return 0;
	}
	if(m==6){
		maxx=-inf;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int m=l+1;m<=n;m++){
							for(int o=m+1;o<=n;o++){
								maxx=max(maxx,(a[i]&a[j]&a[k]&a[l]&a[m]&a[o])*1LL);
							}
						}
					}
				}
			}
		}
		cout<<maxx;
		return 0;
	}
	if(m==7){
		maxx=-inf;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int m=l+1;m<=n;m++){
							for(int o=m+1;o<=n;o++){
								for(int p=o+1;p<=n;p++){
									maxx=max(maxx,(a[i]&a[j]&a[k]&a[l]&a[m]&a[o]&a[p])*1LL);
								}
							}
						}
					}
				}
			}
		}
		cout<<maxx;
		return 0;
	}
	if(m==8){
		maxx=-inf;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int m=l+1;m<=n;m++){
							for(int o=m+1;o<=n;o++){
								for(int p=o+1;p<=n;p++){
									for(int q=p+1;q<=n;q++){
										maxx=max(maxx,(a[i]&a[j]&a[k]&a[l]&a[m]&a[o]&a[p]&a[q])*1LL);
									}
								}
							}
						}
					}
				}
			}
		}
		cout<<maxx;
		return 0;
	}
	if(m==9){
		maxx=-inf;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int m=l+1;m<=n;m++){
							for(int o=m+1;o<=n;o++){
								for(int p=o+1;p<=n;p++){
									for(int q=p+1;q<=n;q++){
										for(int r=q+1;r<=n;r++){
											maxx=max(maxx,(a[i]&a[j]&a[k]&a[l]&a[m]&a[o]&a[p]&a[q]&a[r])*1LL);
										}
									}
								}
							}
						}
					}
				}
			}
		}
		cout<<maxx;
		return 0;
	}
	if(m&1){
		cout<<maxx;
	}else{
		cout<<0;
	}
	
}
