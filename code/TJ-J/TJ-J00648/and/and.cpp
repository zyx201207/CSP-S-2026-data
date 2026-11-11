#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,a[200010],ma=-1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m=1){
		for(int i=1;i<=n;i++){
			if(a[i]>ma){
				ma=a[i];
			}
		}
	}else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[i]&a[j]>ma){
					ma=a[i]&a[j];
				}
			}
		}
	}else if(m==n){
		ma=a[1];
		for(int i=2;i<=n;i++){
			ma=ma&a[i];
		}
	}else if(m==3){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=1;k++){
					if(a[i]&a[j]&a[k]>ma){
						ma=a[i]&a[j];
					}
				}
			}
		}
	}
	cout<<ma;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
