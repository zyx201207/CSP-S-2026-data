#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200009],ma,b;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ma=max(ma,a[i]);
	}
	b=a[1];
	for(int i=2;i<=n;i++){
		b&=a[i];
	}
	if(m==1)cout<<ma;
	if(m==n)cout<<b;
	if(m==2){
		long long e=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				e=max(e,a[i]&a[j]);
			}
		}
		cout<<e;
	}
	if(m==3){
		long long e=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					e=max(e,a[i]&a[j]&a[k]);
				}
			}
		}
		cout<<e;
	}
	if(m==4){
		long long e=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						e=max(e,a[i]&a[l]&a[k]&a[j]);
					}
				}
			}
		}
		cout<<e;
	}
	if(m==5){
		long long e=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int h=l+1;h<=n;h++){
							e=max(e,a[i]&a[l]&a[k]&a[j]&a[h]);
						}
					}
				}
			}
		}
		cout<<e;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}