#include<bits/stdc++.h>
using namespace std;
long long a[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	long long maxn=a[1],sum=a[1];
	for(int i=2;i<=n;i++){
		maxn=max(maxn,a[i]);
		sum=sum&a[i];
	}
	if(m==1){
		cout<<maxn;
		return 0;
	}if(m==n){
		cout<<sum;
		return 0;
	}if(m==2){
		maxn=-9e18;
		for(int i=2;i<=n;i++){
			for(int j=1;j<=i;j++){
				maxn=max(maxn,a[i]&a[j]);
			}
		}
		cout<<maxn;
		return 0;
	}if(m==n-1){
		maxn=-9e18;
		for(int i=1;i<=n;i++){
			if(i!=1){
				sum=a[1];
			}else{
				sum=a[2];
				for(int j=3;j<=n;j++){
					sum=sum&a[j];
				}
				maxn=max(maxn,sum);
				continue;
			}
			for(int j=2;j<=n;j++){
				if(j!=i){
					sum=sum&a[j];
				}
			}
			maxn=max(maxn,sum);
		}
		cout<<maxn;
		return 0;
	}
	cout<<maxn;
	return 0;
} 
