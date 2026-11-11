#include <bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	long long maxans=-1;
	int a[200005]={0};
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			if(a[i]>=maxans) maxans=a[i];
		}
		cout<<maxans;
	}else if(m==2){
		long long f=a[1]&a[2];
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				if(i==j) continue;
				f=a[i]&a[j];
				if(f>=maxans) maxans=f;
			}
		}
		cout<<maxans;
	}else if(m==3){
		long long f=a[1]&a[2]&a[3];
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				for(int k=j;k<=n;k++){
					if(i==j||j==k) continue;
					f=a[i]&a[j]&a[k];
					if(f>=maxans) maxans=f;
				}
			}
		}
		cout<<maxans;
	}else if(m==4){
		long long f=a[1]&a[2]&a[3]&a[4];
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				for(int k=j;k<=n;k++){
					for(int h=k;h<=k;h++){
						if(i==j||j==k||k==h) continue;
						f=a[i]&a[j]&a[k]&a[h];
						if(f>=maxans) maxans=f;
					}
				}
			}
		}
		cout<<maxans;
	}else if(){
		long long f=a[1]&a[2]&a[3]&a[4]&a[5];
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				for(int k=j;k<=n;k++){
					for(int h=k;h<=k;h++){
						for(int l=h;l<=h;l++){
							if(i==j||j==k||k==h||h==l) continue;
							f=a[i]&a[j]&a[k]&a[h]&a[l];
							if(f>=maxans) maxans=f;
						}
					}
				}
			}
		}
		cout<<maxans;
	}else{
		cout<<pow(2,n);
	}
	return 0;
} 
