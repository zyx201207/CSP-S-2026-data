#include<iostream>
#include<cstdio>
#define int long long
using namespace std;
int n,m;
int maxn=-1;
int a[200005];
signed main(){
  	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			int sum=a[i],x=a[i];
			for(int j=i+1;j<=n;j++){
				sum&=a[j];
				maxn=max(maxn,sum);
				sum=x;
			}
		}
		cout<<maxn;
	}
	else if(m==n){
		int sum=a[1];
		for(int i=1;i<=n;i++){
			sum&=a[i]; 
		}
		cout<<sum;
	}
	else if(m==1){
		cout<<0;
	}
	else if(m<=n){
		for(int i=1;i<=n;i++){
			int sum=a[i],x=a[i];
			int y=m;
			for(int j=i;j<=n;j++){
				sum&=a[j];m--;
				if(m==0) {
					maxn=max(maxn,sum);
					sum=x;
				}
			}
		}
		cout<<maxn;
	}
	return 0;
} 
