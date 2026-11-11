#include<bits/stdc++.h>
using namespace std;
int a[100001];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	long long int max=-1;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(m==1){
		sort(a,a+n);
		cout<<a[n-1];
	}else if(m==2){
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				if((a[i]&a[j]) >max){
					max=(a[i]&a[j]);
				}
			}
		}
		cout<<max;
	}else if(m==3){
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				for(int k=j+1;k<n;k++){
					if((a[i]&a[j]&a[k]) >max){
						max=(a[i]&a[j]&a[k]);
					}
				}
			}
		}
		cout<<max;
	}else if(m==4){
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				for(int k=j+1;k<n;k++){
					for(int l=k+1;l<n;l++){
						if((a[i]&a[j]&a[k]&a[l]) >max){
							max=(a[i]&a[j]&a[k]&a[l]);
						}
					}
				}
			}
		}
		cout<<max;
	}else if(m==5){
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				for(int k=j+1;k<n;k++){
					for(int l=k+1;l<n;l++){
						for(int m=l+1;m<n;m++){
							if((a[i]&a[j]&a[k]&a[l]&a[m]) >max){
								max=(a[i]&a[j]&a[k]&a[l]&a[m]);
							}
						}
					}
				}
			}
		}
		cout<<max;
	}
	return 0;
}
