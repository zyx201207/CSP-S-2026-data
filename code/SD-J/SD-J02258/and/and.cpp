#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int a[N];
int main(){
	//æÕ‹šæÕ‹šæÕ‹šæÕ‹šìhìhìhæÕ‹š
	//freopen("and.in","r",stdin);
	//freopen("and.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	if(m==1){
		int ma=0;
	    for(int i=1;i<=n;i++){
		    ma=max(ma,a[i]);
    	}
    	cout<<ma;
	}
	if(m==n){
		int s=a[1],i=2;
		while(i!=n){
			s=s & a[i];
			i++;
		}
		cout<<s;
	}
	if(m==2){
		int ma=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n&&j!=i;j++){
				ma=max(ma,a[i] & a[j]);
			}
		}
		printf("%d",ma);
		return 0;
	}
	if(m==3){
		int ma=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n&&j!=i;j++){
				for(int k=1;k<=n&&k!=j&&k!=i;k++){
					ma=max(ma,a[i] & a[j] & a[k]);
				}	
			}
		}
		printf("%d",ma);
		return 0;
	}
	if(m==4){
		int ma=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n&&j!=i;j++){
				for(int k=1;k<=n&&k!=j&&k!=i;k++){
					for(int p=1;p<=n&&p!=k&&p!=j&&p!=i;p++){
				    	ma=max(ma,a[i] & a[j] & a[k] & a[p]);
					}
				}	
			}
		}
		printf("%d",ma);
		return 0;
	}
	if(m==5){
		int ma=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n&&j!=i;j++){
				for(int k=1;k<=n&&k!=j&&k!=i;k++){
					for(int p=1;p<=n&&p!=k&&p!=j&&p!=i;p++){
				    	for(int q=1;q<=n&&q!=p&&q!=k&&q!=j&&q!=i;q++){
				        	ma=max(ma,a[i] & a[j] & a[k] & a[p] & a[q]);
					    }
					}
				}	
			}
		}
		printf("%d",ma);
		return 0;
	}
	if(m==6){
		int ma=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n&&j!=i;j++){
				for(int k=1;k<=n&&k!=j&&k!=i;k++){
					for(int p=1;p<=n&&p!=k&&p!=j&&p!=i;p++){
				    	for(int q=1;q<=n&&q!=p&&q!=k&&q!=j&&q!=i;q++){
				    		for(int r=1;r<=n&&r!=p&&r!=k&&r!=j&&r!=i&&r!=q;r++){
				    	    	ma=max(ma,a[i] & a[j] & a[k] & a[p] & a[q] & a[r]);
				            }
					    }	
					}
				}	
			}
		}
		printf("%d",ma);
		return 0;
	}
	if(m==7){
		int ma=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n&&j!=i;j++){
				for(int k=1;k<=n&&k!=j&&k!=i;k++){
					for(int p=1;p<=n&&p!=k&&p!=j&&p!=i;p++){
				    	for(int q=1;q<=n&&q!=p&&q!=k&&q!=j&&q!=i;q++){
				    		for(int r=1;r<=n&&r!=p&&r!=k&&r!=j&&r!=i&&r!=q;r++){
				    	    	for(int s=1;s<=n&&s!=p&&s!=k&&s!=j&&s!=i&&s!=q&&s!=r;s++){
				    	    	    ma=max(ma,a[i] & a[j] & a[k] & a[p] & a[q] & a[r] & a[s]);
				                }
				            }
					    }	
					}
				}	
			}
		}
		printf("%d",ma);
		return 0;
	}
	if(m==8){
		int ma=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n&&j!=i;j++){
				for(int k=1;k<=n&&k!=j&&k!=i;k++){
					for(int p=1;p<=n&&p!=k&&p!=j&&p!=i;p++){
				    	for(int q=1;q<=n&&q!=p&&q!=k&&q!=j&&q!=i;q++){
				    		for(int r=1;r<=n&&r!=p&&r!=k&&r!=j&&r!=i&&r!=q;r++){
				    	    	for(int s=1;s<=n&&s!=p&&s!=k&&s!=j&&s!=i&&s!=q&&s!=r;s++){
				    	    	    for(int t=1;t<=n&&t!=p&&t!=k&&t!=j&&t!=i&&t!=q&&t!=r&&t!=s;t++){
				    	    	        ma=max(ma,a[i] & a[j] & a[k] & a[p] & a[q] & a[r] & a[s] & a[t]);
				                    }
				                }
				            }
					    }	
					}
				}	
			}
		}
		printf("%d",ma);
		return 0;
	}
	if(m==9){
		int ma=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n&&j!=i;j++){
				for(int k=1;k<=n&&k!=j&&k!=i;k++){
					for(int p=1;p<=n&&p!=k&&p!=j&&p!=i;p++){
				    	for(int q=1;q<=n&&q!=p&&q!=k&&q!=j&&q!=i;q++){
				    		for(int r=1;r<=n&&r!=p&&r!=k&&r!=j&&r!=i&&r!=q;r++){
				    	    	for(int s=1;s<=n&&s!=p&&s!=k&&s!=j&&s!=i&&s!=q&&s!=r;s++){
				    	    	    for(int t=1;t<=n&&t!=p&&t!=k&&t!=j&&t!=i&&t!=q&&t!=r&&t!=s;t++){
				    	    	        for(int u=1;u<=n&&u!=p&&u!=k&&u!=j&&u!=i&&u!=q&&u!=r&&u!=s&&u!=t;u++){
				    	    	            ma=max(ma,a[i] & a[j] & a[k] & a[p] & a[q] & a[r] & a[s] & a[t] & a[u]);
				                        }
				                    }
				                }
				            }
					    }	
					}
				}	
			}
		}
		printf("%d",ma);
		return 0;
	}
	cout<<4;
	return 0;
} 
