#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[200099];
long long sum;
long long ans[50001][3001];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		long long ma=0;
		for(int i=1;i<=n;i++){
			ma=max(ma,a[i]);
		}
		cout<<ma;
		return 0;
	}
	else if(m==2){
		long long ma=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(j==i){
					continue;
				}
				ma=max(ma,a[i]&a[j]);
			}
		}
		cout<<ma;
		return 0;
	}
	else if(m==3){
		long long ma=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(j==i){
					continue;
				}
				for(int k=1;k<=n;k++){
					if(k==i || k==j){
						continue;
					}
					ma=max(ma,(a[i]&a[j])&a[k]);
				}
			}
		}
		cout<<ma;
		return 0;
	}
	else if(m==4){
		long long ma=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(j==i){
					continue;
				}
				for(int k=1;k<=n;k++){
					if(k==i || k==j){
						continue;
					}
					for(int i2=1;i2<=n;i2++){
						if(i2==i || i2==j || i2==k){
							continue;
						}
						ma=max(ma,((a[i]&a[j])&a[k])&a[i2]);
					}
				}
			}
		}
		cout<<ma;
		return 0;
	}
	else if(m==5){
		long long ma=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(j==i){
					continue;
				}
				for(int k=1;k<=n;k++){
					if(k==i || k==j){
						continue;
					}
					for(int i2=1;i2<=n;i2++){
						if(i2==i || i2==j || i2==k){
							continue;
						}
						for(int j2=1;j2<=n;j++){
							if(j2==i2 || j2==i || j2==j || j2==k){
								continue;
							}
							ma=max(ma,(((a[i]&a[j])&a[k])&a[i2])&a[j2]);
						}
					}
				}
			}
		}
		cout<<ma;
		return 0;
	}
	cout<<7;
	return 0;
}
