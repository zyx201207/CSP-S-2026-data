#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int a,b,c[100000],d=1,e=1,f=1,g=0,h=1,k[1000][100];
	cin>>a>>b;
	for(int i=1;i<=a;i++){
		cin>>c[i];
	}
	for(int i=1;i<=a;i++){
		d=1;
		for(int j=1;j<=c[i];j++){
			e=1;
			f=1;
			
		for(int z=1;z<d;z++){
		e*=2;
		f+=e;
	}
	if(f==c[i]){
		for(int z=0;z<d;z++){
		k[i][z]=1;
	}
	}
		d++;
	}
	}
	for(int i=1;i<=a;i++){
		
		for(int j=0;j<1000;j++){
			e=1;
			f=1;
			for(int z=0;z<=a;z++){
			e*=2;
			f+=e;
			if(k[i][j]==k[i+z][j] || k[i][j]==1){
				g+=f;
			}
			}
			if(h<g){
				h=g;
			}
			
			
			
		}
	}
	cout<<h;
	return 0;}
