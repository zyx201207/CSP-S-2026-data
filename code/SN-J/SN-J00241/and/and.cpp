#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,k=-1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		k=max(k,a[i]);
	}
	if(n<=20){
		int mx=-1;
		for(int i=0;i<pow(2,n);i++){
			int k=pow(2,n+1)-1,s=0;
			for(int j=0;j<n;j++){
				if(((i>>j)&1) and s<m){
					k&=a[j+1];
					s++;
				}
			}
			if(s!=3){
				continue;
			}
			mx=max(mx,k);
		}
		cout<<mx;
	}
	else if(m==1 and n<=2000){
		cout<<k;
	}
	else if(m==2 and n<=2000){
		int k2=-1;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				k2=max(k2,a[i]&a[j]);
			}
		}
		cout<<k2;
	}
	else if(m==n){
		for(int i=1;i<n;i++){
			a[i+1]%=a[i];
		}
		cout<<a[n];
	}
	else{
		int f=pow(2,22)-1;
		for(int i=n;i>=n-m+1;i--){
			f&=a[i];
		}
		cout<<f;
	}
	return 0;
}
