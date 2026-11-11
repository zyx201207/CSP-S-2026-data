#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500001],b[500001],c[200001],f;
int x(int z,int y){
	for(int i=1;i<y;i++){
		if(b[i]==z){
			return i;
		}
	}
	return 0;
}
int fg(int fgr,int fgi){
	for(int j=fgr;j<fgi;j++){
		for(int i=fgr;i<n;i++){
			b[fgr]=b[fgr+1];
		}
		b[fgi]=0;
	}
	return 0;
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
	} 
	for(int l=1;l<=n;l++){
		for(int i=l;i<=n;i++){
			int r=x(a[i],i);
			if(r!=0){
				fg(r,i);
			}
		}
		for(int i=1;i<=m;i++){
			for(int j=1;j<=n;j++){
				if(b[j]==i){
					c[i]++;
				}
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
}
