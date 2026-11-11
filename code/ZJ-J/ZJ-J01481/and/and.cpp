#include<bits/stdc++.h>
using namespace std;
int n,m,s,ks=1,a[200005],ma=-100,mt=1,mk=1;
int main(){
	//addÆ­·Ö 
	freopen("add.in","r",stdin);
	freopen("add.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ks=ks&a[i];
		mt=max(mt,a[i]);
	}
	if(n<=20){
	}else{
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				ma=max(ma,a[i]&a[j]);
			}
		}
	}
	if(m==n-1){
		for(int i=1;i<=n;i++){
			for(int j=1;j<i;j++){
				mk=mk&a[j];
			}
			for(int j=i+1;j<=n;j++){
				mk=mk&a[j];
			}
	    }
    } 
	if(n==m){
		cout<<ks;
	}else if(m==2){
		cout<<ma;
	}else if(m==1){
		cout<<mt;
	}else if(m==n-1){
		cout<<mk;
	}
	return 0;
}
