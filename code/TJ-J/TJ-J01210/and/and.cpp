#include<bits/stdc++.h>
using namespace std;

long long n,m,k;
int a[200005],sum[200005],ma;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=20){
		if(m==1){
			sort(a+1,a+1+n);
			cout<<a[n];
		}
		else if(m==2){
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					ma=max(a[i]&a[j],ma);
				}
			}
			cout<<ma;
		}
		else if(m==3){
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					for(int k=j+1;k<=n;k++){
						ma=max(a[i]&a[j]&a[k],ma);
					} 
				}
			}
			cout<<ma;
		}
		else if(m==4){
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					for(int k=j+1;k<=n;k++){
						for(int w=k+1;w<=n;w++){
						
							ma=max(a[i]&a[j]&a[k]&a[w],ma);
						}
					} 
				}
			}
			cout<<ma;
		}
		else if(m==5){
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					for(int k=j+1;k<=n;k++){
						for(int w=k+1;w<=n;w++){
							for(int g=w+1;g<=n;g++){
								ma=max(a[i]&a[j]&a[k]&a[w],ma);
							}
							
						}
					} 
				}
			}
			cout<<ma;
		}
	}
	if(n<=2000&&n>20){
		if(m==1){
			sort(a+1,a+1+n);
			cout<<a[n];
		}
		else if(m==2){
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					ma=max(a[i]&a[j],ma);
				}
			}
			cout<<ma;
		}
		else if(m==n){
			k=a[n];
			for(int i=1;i<=n;i++){
				k=k&a[i];
			}
			cout<<k;
		}
	}
	if(n>2000&&n<=2*100000){
		sort(a+1,a+1+n);
		reverse(a+1,a+1+n);
		k=a[1];
		for(int i=1;i<=m;i++){
			k=k&a[i];
		} 
		cout<<k;
	}
	
	
	return 0;
}
