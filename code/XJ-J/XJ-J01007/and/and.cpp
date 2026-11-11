#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[300000];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		long long maxx=-1;
		for(int i=1;i<=n;i++){
			if(a[i]>maxx){
				maxx=a[i];
			}
		}
		cout<<maxx;
	}else if(m==2){
		long long maxx=-1,z;
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				z=a[i]&a[j];
				if(z>maxx){
					maxx=z;
				}
			}
		}
		cout<<maxx;
	}else if(m==n){
		long long z=a[1];
		for(int i=2;i<=n;i++){
			z=z&a[i];
		}
		cout<<z;
	}else if(m==3){
		long long maxx=-1,z;
		for(int i=1;i<n-1;i++){
			for(int j=i+1;j<n;j++){
				for(int k=j+1;k<=n;k++){
					z=a[i]&a[j]&a[k];
					if(z>maxx){
						maxx=z;
					}
				}
			}
		}
		cout<<maxx;
	}else if(m=n-1){
		long long maxx=-1,z;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(j!=i){
					z=z&a[j];
				}
			}
			if(z>maxx){
					maxx=z;
				}
		}
		cout<<maxx;
	}
	return 0;
}