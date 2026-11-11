#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);	
	int n,m;
	cin>>n>>m;
	int a[n+1];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
		int b=-1;
		bool c[n+1]={0};int g=0,h=0;
		for(int j=1;j<n;j++){
			for(int k=j+1;k<=n;k++){
				if(b<(a[j]&a[k])){
					b=a[j]&a[k];
					g=j;h=k;
				}
			}
		}
		c[g]=1;c[h]=1;
	for(int i=2;i<m;i++){
		int d=b;
		g=1;
		bool f=1;
		for(int j=1;j<=n;j++){
			if(!c[j]){
				if(f){
					b=b&a[j];
					f=0;
					continue;
				}
				if(b<d&a[j]){
					b=d&a[j];
					g=j;	
				}			
			}
		}
		c[g]=1;
	}
	cout<<b;
	return 0;
}
