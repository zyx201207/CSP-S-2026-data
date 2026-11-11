#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int ma=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ma=max(ma,a[i]);
	}
	long long maxx=0;
	long long t;
	if(m==1){
		cout<<ma;
	}else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(j==i){
					continue;
				}
				t=a[j]&a[i];
				maxx=max(maxx,t);
			}
		}
		cout<<maxx;
	}else if(m==3){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int x=j+1;x<=n;x++){
					t=a[j]&a[i]&a[x];
					maxx=max(maxx,t);
				}
			}
		}
		cout<<maxx;
	}else if(m==4){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int x=j+1;x<=n;x++){
					for(int y=x+1;y<=n;y++){
						t=a[j]&a[i]&a[x]&a[y];
						maxx=max(maxx,t);
					}
					
				}
			}
		}
		cout<<maxx;
	}else if(m==5){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int x=j+1;x<=n;x++){
					for(int y=x+1;y<=n;y++){
						for(int b=y+1;b<=n;b++){
							t=a[j]&a[i]&a[x]&a[y]&a[b];
							maxx=max(maxx,t);
						}
					}
					
				}
			}
		}
		cout<<maxx;
	}else if(m==6){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int x=j+1;x<=n;x++){
					for(int y=x+1;y<=n;y++){
						for(int b=y+1;b<=n;b++){
							for(int c=b+1;c<=n;c++){
								t=a[j]&a[i]&a[x]&a[y]&a[b]&a[c];
								maxx=max(maxx,t);
							}
						}
					}
					
				}
			}
		}
		cout<<maxx;
	}else if(m==7){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int x=j+1;x<=n;x++){
					for(int y=x+1;y<=n;y++){
						for(int b=y+1;b<=n;b++){
							for(int c=b+1;c<=n;c++){
								for(int d=c+1;d<=n;d++){
									t=a[j]&a[i]&a[x]&a[y]&a[b]&a[c]&a[d];
									maxx=max(maxx,t);
								} 
							}
						}
					}
					
				}
			}
		}
		cout<<maxx;
	}
	return 0;
} 


