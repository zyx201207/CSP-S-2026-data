#include<bits/stdc++.h>
using namespace std;
int n,k;
int maxx=0;
int a[1005];
bool cmp(int x,int y){
	return x>y;
}
int f(int x,int y){
	int z=0;
	int t=0;
	while(x!=0&&y!=0){
		int p,q;
		p=x%2;
		q=y%2;
		if(p==q&&p==1) z+=pow(2,t);
		t++;
		x/=2;
		y/=2;
	}
	return z;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(k==1){
		for(int i=1;i<=n;i++){
			maxx=max(maxx,a[i]);
			cout<<maxx;
			return 0;
		}
	}
	else if(k==2){
		sort(a+1,a+n+1,cmp);
		
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				int z=f(a[i],a[j]);
				maxx=max(maxx,z);
			}
		}
		cout<<maxx;
		return 0;
	}
	else if(k==3){
		sort(a+1,a+n+1,cmp);
		
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int o=j+1;o<=n;o++){
					int z=f(a[i],f(a[j],a[o]));
					maxx=max(maxx,z);
				}
				
			}
		}
		cout<<maxx;
		return 0;
	}
	else if(k==4){
		sort(a+1,a+n+1,cmp);
		
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int o=j+1;o<=n;o++){
					for(int l=o+1;l<=n;l++){
						int z=f(a[i],f(a[j],f(a[o],a[l])));
						maxx=max(maxx,z);
					}
					
				}
				
			}
		}
		cout<<maxx;
		return 0;
	}
	else if(k==5){
		sort(a+1,a+n+1,cmp);
		
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int o=j+1;o<=n;o++){
					for(int l=o+1;l<=n;l++){
						for(int r=l+1;r<=n;r++){
							int z=f(a[i],f(a[j],f(a[o],f(a[l],a[r]))));
							maxx=max(maxx,z);
						}
						
					}
					
				}
				
			}
		}
		cout<<maxx;
		return 0;
	}
	else if(k==6){
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int o=j+1;o<=n;o++){
					for(int l=o+1;l<=n;l++){
						for(int r=l+1;r<=n;r++){
							for(int p=r+1;p<=n;p++){
								int z=f(a[i],f(a[j],f(a[o],f(a[l],f(a[r],a[p])))));
							maxx=max(maxx,z);
							}
							
						}
						
					}
					
				}
				
			}
		}
		cout<<maxx;
		return 0;
	}
}
