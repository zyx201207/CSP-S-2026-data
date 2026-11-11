#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

long long a[200010];

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	int u=1;
	for(int i=1;i<=n;i++){
		int v=0;
		for(int j=1;j<=30;j++){
			if(a[i]==pow(2,j)-1){
				v=1;
				break;
			}
		}
		if(v==0){
			u=0;
			break;
		}
	}
	if(u==1){
		long long mmm=0;
		for(int i=1;i<=n;i++){
			if(a[i]>mmm) mmm=a[i];
		}
		cout<<mmm;
	}else{
		long long x=0;
		if(m==1){
			for(int i=1;i<=n;i++){
				if(a[i]>x) x=a[i];
			}
		}else if(m==2){
			for(int i=1;i<n;i++){
				for(int j=i+1;j<=n;j++){
					if(a[i]&a[j]>x) x=a[i]&a[j];
					}
			}
		}else if(m==n){
			x=a[1];
			for(int i=2;i<=n;i++) x&a[i];
		}else if(m==n-1){
			long long y=10e17+999999999999999999;
			x=a[1];
			for(int i=1;i<=n;i++){
				if(a[i]<y) y=a[i];
			}
			for(int i=2;i<=n;i++){
				if(a[i]!=y) x&a[i];
			}
		}else if(m==3){
			for(int i=1;i<n-1;i++){
				for(int j=i+1;j<n;j++){
					for(int k=j+1;k<=n;k++){
						if(a[i]&a[i]&a[k]>x) x=a[i]&a[j]&a[k];
					}
				}
			}
		}
		cout<<x;
	}
	return 0;
}
