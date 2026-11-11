#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],ma=0,s=pow(2,31)-1;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		ma=max(a[i],ma);
		s&=a[i];
	}
	if(m==1){
		printf("%d",ma);
		return 0;
	}
	if(m==n){
		printf("%d",s);
		return 0;
	}
	int ans=0;
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		} 
		printf("%d",ans);
	}
	if(m==3){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					ans=max(ans,a[i]&a[j]&a[k]);
				}	
			}
		} 
		printf("%d",ans);
	}
	if(m==4){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int ii=k+1;ii<=n;ii++){
						ans=max(ans,a[i]&a[j]&a[k]&a[ii]);
					}
				}	
			}
		} 
		printf("%d",ans);
	}
	if(m==5){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int ii=k+1;ii<=n;ii++){
						for(int ij=ii+1;ij<=n;ij++){
							ans=max(ans,a[i]&a[j]&a[k]&a[ii]&a[ij]);
						}
					}
				}	
			}
		} 
		printf("%d",ans);
	}
	if(m==6){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int ii=k+1;ii<=n;ii++){
						for(int ij=ii+1;ij<=n;ij++){
							for(int ik=ij+1;ik<=n;ik++){
								ans=max(ans,a[i]&a[j]&a[k]&a[ii]&a[ij]&a[ik]);
							}
						}
					}
				}	
			}
		} 
		printf("%d",ans);
	}
	if(m==7){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int ii=k+1;ii<=n;ii++){
						for(int ij=ii+1;ij<=n;ij++){
							for(int ik=ij+1;ik<=n;ik++){
								for(int ji=ik+1;ji<=n;ji++){
									ans=max(ans,a[i]&a[j]&a[k]&a[ii]&a[ij]&a[ik]&a[ji]);
								}							
							}
						}
					}
				}	
			}
		} 
		printf("%d",ans);
	}
	if(m==8){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int ii=k+1;ii<=n;ii++){
						for(int ij=ii+1;ij<=n;ij++){
							for(int ik=ij+1;ik<=n;ik++){
								for(int ji=ik+1;ji<=n;ji++){
									for(int jj=ji+1;jj<=n;jj++){
										ans=max(ans,a[i]&a[j]&a[k]&a[ii]&a[ij]&a[ik]&a[ji]&a[jj]);
									}
								}							
							}
						}
					}
				}	
			}
		} 
		printf("%d",ans);
	}
	if(m==9){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int ii=k+1;ii<=n;ii++){
						for(int ij=ii+1;ij<=n;ij++){
							for(int ik=ij+1;ik<=n;ik++){
								for(int ji=ik+1;ji<=n;ji++){
									for(int jj=ji+1;jj<=n;jj++){
										for(int jk=jj+1;jk<=n;jk++){
											ans=max(ans,a[i]&a[j]&a[k]&a[ii]&a[ij]&a[ik]&a[ji]&a[jj]&a[jk]);
										}
									}
								}							
							}
						}
					}
				}	
			}
		} 
		printf("%d",ans);
	}
	
	return 0;
}
