#include<bits/stdc++.h>
using namespace std;
int a[200005];
int n,m;
int ans;
int anss;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==m){
		for(int i=1;i<=n;i++){
			if(i==1){
				ans=a[i];
			}else{
				ans=ans&a[i];
			}
		}cout<<ans<<endl;
		return 0;
	}
	
	if(m==n-1){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(j==1){
					anss=a[j];
				}else if(j==i){
					continue;
				}else{
					anss=anss&a[j];
				}
			}
			ans=max(ans,anss);
		}
		cout<<ans<<endl;
		return 0;
	}
	
	if(m==1){
		for(int i=1;i<=n;i++){
			ans=max(ans,a[i]);
		}
		cout<<ans<<endl;
		return 0;
	}
	
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				anss=a[i]&a[j];
				ans=max(anss,ans);
			}
		}
	}
	
	if(m==3){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int h=j+1;h<=n;h++){
					anss=a[i]&a[j]&a[h];
					ans=max(anss,ans);
				}	
			}
		}
	}
	
	if(m==4){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int h=j+1;h<=n;h++){
					for(int k=h+1;k<=n;k++){
						anss=a[i]&a[j]&a[h]&a[k];
						ans=max(anss,ans);
					}	
				}
			}
		}
	}
	
	if(m==5){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int h=j+1;h<=n;h++){
					for(int k=h+1;k<=n;k++){
						for(int t=k+1;t<=n;t++){
							anss=a[i]&a[j]&a[h]&a[k]&a[t];
							ans=max(anss,ans);
						}
					}	
				}
			}
		}
	}
	
	if(m==6){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int h=j+1;h<=n;h++){
					for(int k=h+1;k<=n;k++){
						for(int t=k+1;t<=n;t++){
							for(int y=t+1;y<=n;y++){
								anss=a[i]&a[j]&a[h]&a[k]&a[t]&a[y];
								ans=max(anss,ans);
							}	
						}
					}	
				}
			}
		}
	}
	
	if(m==7){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int h=j+1;h<=n;h++){
					for(int k=h+1;k<=n;k++){
						for(int t=k+1;t<=n;t++){
							for(int y=t+1;y<=n;y++){
								for(int l=y+1;l<=n;l++){
									anss=a[i]&a[j]&a[h]&a[k]&a[t]&a[y]&a[l];
									ans=max(anss,ans);
								}	
							}	
						}
					}	
				}
			}
		}
	}
	
	if(m==8){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int h=j+1;h<=n;h++){
					for(int k=h+1;k<=n;k++){
						for(int t=k+1;t<=n;t++){
							for(int y=t+1;y<=n;y++){
								for(int l=y+1;l<=n;l++){
									for(int g=l+1;l<=n;g++){
										anss=a[i]&a[j]&a[h]&a[k]&a[t]&a[y]&a[l]&a[j];
										ans=max(anss,ans);
									}	
								}	
							}	
						}
					}	
				}
			}
		}
	}
	
	if(m==9){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int h=j+1;h<=n;h++){
					for(int k=h+1;k<=n;k++){
						for(int t=k+1;t<=n;t++){
							for(int y=t+1;y<=n;y++){
								for(int l=y+1;l<=n;l++){
									for(int g=l+1;l<=n;g++){
										for(int v=g+1;v<=n;v++){
											anss=a[i]&a[j]&a[h]&a[k]&a[t]&a[y]&a[l]&a[j]&a[v];
											ans=max(anss,ans);
										}
									}	
								}	
							}	
						}
					}	
				}
			}
		}
	}
	
	if(m==10){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int h=j+1;h<=n;h++){
					for(int k=h+1;k<=n;k++){
						for(int t=k+1;t<=n;t++){
							for(int y=t+1;y<=n;y++){
								for(int l=y+1;l<=n;l++){
									for(int g=l+1;l<=n;g++){
										for(int v=g+1;v<=n;v++){
											for(int jk=v+1;jk<=n;jk++){
												anss=a[i]&a[j]&a[h]&a[k]&a[t]&a[y]&a[l]&a[j]&a[v]&a[jk];
												ans=max(anss,ans);
											}	
										}
									}	
								}	
							}	
						}
					}	
				}
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

