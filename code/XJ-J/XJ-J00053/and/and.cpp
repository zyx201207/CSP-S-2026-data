#include<bits/stdc++.h>
using namespace std;
int a[200005];int n,m,minn=-1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(m==2){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(i!=j)
					minn=max(minn,a[i]&a[j]);
			}
		}
	}else if(m==3){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
			    for(int x=0;x<n;x++){
			    	if(i!=j&&j!=x&&x!=i)
						minn=max(minn,a[i]&a[j]&a[x]);
				}
			}
		}
	}else if(m==4){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
			    for(int x=0;x<n;x++){
			    	for(int y=0;y<n;y++){
				    	if(i!=j&&j!=x&&x!=i&&i!=y&&j!=y&&x!=y)
							minn=max(minn,a[i]&a[j]&a[x]&a[y]);
					}	
				}
			}
		}
	}else if(m==5){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
			    for(int x=0;x<n;x++){
			    	for(int y=0;y<n;y++){
			    		for(int z=0;z<n;z++){
							if(i!=j&&j!=x&&x!=i&&i!=y&&j!=y&&y!=z&&x!=z&&i!=z&&j!=z)
								minn=max(minn,a[i]&a[j]&a[x]&a[y]&a[x]);
						}
					}	
				}
			}
		}
	}else if(m==6){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
			    for(int x=0;x<n;x++){
			    	for(int y=0;y<n;y++){
			    		for(int z=0;z<n;z++){
			    			for(int u=0;u<n;u++){
				    			if(i!=j&&j!=x&&x!=i&&i!=y&&j!=y&&y!=z&&x!=z&&i!=z&&j!=z&&z!=u&&j!=u&&y!=u&&i!=u&&x!=u)
									minn=max(minn,a[i]&a[j]&a[x]&a[y]&a[x]&a[u]);
							}
						}
				    	
					}	
				}
			}
		}
	}
	cout<<minn;
	return 0;
}
