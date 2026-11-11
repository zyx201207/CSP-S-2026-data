#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,x=0,vv,vb;
	cin>>n>>m;
	long long a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int k=0;k<m-1;k++){
		for(int i=0;i<n-1;i++){
			for(int j=i;j<n;j++){
				if(a[i]&&a[j]>x){
					x=a[i]&&a[j];
					vv=a[i];
					vb=a[j];
				}
			}
		}
		long long b[n-k+1];
		for(int i=0;i<n-k+1;i++){
			if(a[i]==vv){
				b[i]=x;
			}
			else{
				if(a[i]!=vb){
					b[i]=a[i];
				}
			}
		}
	}
	cout<<x;
}
