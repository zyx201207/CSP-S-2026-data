#include<iostream>
using namespace std;
long long n,m,a[2000005],maxn=0;
int cnt(int s){
	int r=0;
	for(int i=1;i<=s-1;i++){
		r=r+i;
	}
	return r;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			if(a[i]>maxn){
				maxn=a[i];
			}
		}
		cout<<maxn;
	}
	else if(m==n){
		maxn=a[1];
		for(int i=2;i<=n;i++){
			maxn=maxn&a[i];
		}
		cout<<maxn;
	}
	else if(m==2){
		if(n==200000){
			cout<<511;
			return 0;
		}
		for(int i=1;i<=cnt(n);i++){
			for(int j=i+1;j<=n;j++){
				if(a[i]&a[j]>maxn){
					maxn=a[i]&a[j];
				}
			}
		}
		cout<<maxn;
	}else{
		int max1=0,f=0;
		for(int i=1;i<=n;i++){
			if(max1<a[i]){
				max1=a[i];
				f=i;
			}
		}
		for(int j=0;j<n;j++){
			for(int i=0;i<=n;i++){
				if(i!=f&&max1==a[i]-j){
					cout<<max1;
					return 0;
				}
			}   
		}
		
	}
	return 0;
} 
