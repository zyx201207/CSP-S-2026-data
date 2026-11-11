#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,x=0,y=2,z=0;
	cin>>n>>m;
	int a[1000000];
	int b[1000000][1000000];
	int c[1000000][1000000];
	int d[1000000];
	for(int i=0;i<n;i++){
		cin>>a[i];
		while(a[i]<=1){
			b[i][x]=a[i]%2;
			a[i]/2;
			x++;
		}
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<x;j++){
			if(b[i][j]==1&&b[i+1][j]==1){
				c[i][j]=1;
			}
			else{
				c[i][j]=0;
			}
		}
	}
	for(int i=0;i<x;i++){
		for(int j=1;j<=n;j++){
			if(c[i][j]==1){
				for(int k=1;k<=j;k++){
					y=y*2;
				}
				z=z+y;
			}
			d[i]=z;
		}
	}
	sort(d+0,d+n);
	cout<<d[x];
	
}
