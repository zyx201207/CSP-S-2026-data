#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int m,n,a[100100];
	int maxx=-1;
	cin>>n>>m;
	for(int x=0;x<n;x++) cin>>a[x];
	if(m==1){
		for(int x=0;x<n;x++) maxx=max(maxx,a[x]);
	}else if(m==2){
		for(int x=0;x<n;x++){
			for(int y=x+1;y<n;y++){
				int sum=a[x]&a[y];
				maxx=max(maxx,sum);
			}
		}
	}else if(m==3){
		for(int x=0;x<n;x++){
			for(int y=x+1;y<n;y++){
				for(int z=x+y+1;z<n;z++){
					int sum=a[x]&a[y]&a[z];
					maxx=max(maxx,sum);
				}
			}
		}
	}else if(m==4){
		for(int x=0;x<n;x++){
			for(int y=x+1;y<n;y++){
				for(int z=x+y+1;z<n;z++){
					for(int xx=x+y+z+1;xx<n;xx++){
						int sum=a[x]&a[y]&a[z]&a[xx];
						maxx=max(maxx,sum);
					}
				}
			}
		}
	}else if(m==5){
		for(int x=0;x<n;x++){
			for(int y=x+1;y<n;y++){
				for(int z=x+y+1;z<n;z++){
					for(int xx=x+y+z+1;xx<n;xx++){
						for(int yy=x+y+z+xx+1;yy<n;yy++){
							int sum=a[x]&a[y]&a[z]&a[xx]&a[yy];
							maxx=max(maxx,sum);
						}
					}
				}
			}
		}
	}else if(m==6){
		for(int x=0;x<n;x++){
			for(int y=x+1;y<n;y++){
				for(int z=x+y+1;z<n;z++){
					for(int xx=x+y+z+1;xx<n;xx++){
						for(int yy=x+y+z+xx+1;yy<n;yy++){
							for(int zz=x+y+z+xx+yy;zz<n;zz++){
								int sum=a[x]&a[y]&a[z]&a[xx]&a[yy]&a[zz];
								maxx=max(maxx,sum);
							}
						}
					}
				}
			}
		}
	}else if(m==n){
		int sum=a[0];
		for(int x=1;x<m;x++) sum&=a[x];
		maxx=sum;
	}else if(m==n-1){
		for(int x=0;x<n;x++){
			int sum;
			bool fir=true;
			for(int y=0;y<n;y++){
				if(fir==true&&y!=x){
					sum=a[y];
					fir=false;
				}
				if(y!=x) sum&=a[y];
			}
			maxx=max(maxx,sum);
		}
	}
	printf("%d",maxx);
	return 0;
}

