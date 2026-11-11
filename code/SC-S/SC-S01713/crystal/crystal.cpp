#include <bits/stdc++.h>
using namespace std; 
int n,m,a[1001],cs=0,zj,zd,zx=1,b=0,sz,jl=0,q[1001];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdin);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b+=a[i];
		}
		for(int i=1;i<=m;i++){
			if(zd<a[i]){
				zd=a[i];
			}
			if(zx>a[i]){
				zx=a[i];
			}
		}
		int pj;
		b=b-zd-zx;
		pj=b/(n-2);
	
		for(int i=1;i<=n;i++){
			if(a[i]-pj<zx and a[i]-pj>=0){
				b=a[i];
			}
		}
		for(int i=1;i<=n;i++){
			if(a[i]<0){
				b--;
				break;
				}	
			}
		zj=b;
		for(int i=1;i<=n;i++){
			if(a[i]==zj){
				jl++;
			}
		}
		for(int i=1;i<=m;i++){
			if(zj-a[i]<=m){
			jl++;
			m=m-zj+a[i];
			}
			else{
				break;
			}
		}
		
	cout<<jl;	
	return 0;
}