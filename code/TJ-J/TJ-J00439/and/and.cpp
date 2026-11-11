#include <bits/stdc++.h>
#include <cstdio>
int n,m,a[200005],b[200005],c;
using namespace std;
int main(){
	freopen("and.in","r",stdin);
   	freopen("and.out","w",stdout);
   	cin>>n>>m;
   	for(int i=0;i<n;i++){
   		cin>>a[i];
	}
	if(m==1){
		sort(a,a+n);
		cout<<a[n-1];
	}else{
		for(int i=0;i<n;i++){
			for(int k=i+1;k<n;k++){
				for(int j=0;j<m-1;j++){
					b[i]=a[i]&a[k];
				}	
			}	
		}
		sort(b,b+n);
		cout<<b[n-1];
	}
	return 0;
}
