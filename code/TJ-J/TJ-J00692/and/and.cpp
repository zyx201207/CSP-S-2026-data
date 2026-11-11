#include<bits/stdc++.h>
using namespace std;
int main(){ 
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,b[100];
	cin>>n>>m;
	int c[100],f=0,g=0;
	int a[100][100],l=0,l1=0;
	int lon[100];
	for(int i=0;i<n;i++){
		cin>>b[i]; 
		for(int j=1;j>0;j=j*2){
		if(j>b[i]){
			l1=j/2;
			
			break;
		}
	}
			while(b[i]!=0){
		
			a[i][l]=1;
			l++;
			b[i]=b[i]-l1;
			l1=l1/2;
				while(b[i]<l1){
				a[i][l]=0;
				l++;
				l1=l1/2;
			}
			}
			lon[i]=l;
			l1=0;
			l=0;
			
	}
	for(int j=0;j<lon[0];j++){
		if(a[0][j]==a[1][j]&&a[0][j]==1){
			c[j]==1;
		}
		else{
			c[j]=0;
		}}
		l1=1;
		for(int v=0;v<lon[0];v++){
		if(c[v]==1){
			f=f+l1;
		}
		l1*2;
	}l1=0;
	if(f>=g){
		g=f;
	}for(int j=0;j<lon[1];j++){
	if(a[1][j]==a[2][j]&&a[1][j]==1){
			c[j]==1;
		}
		else{
			c[j]=0;
		}}
		l1=1;
		for(int v=0;v<lon[1];v++){
		if(c[v]==1){
			f=f+l1;
		}
		l1*2;
	}l1=0;
	if(f>=g){
		g=f;
	}
	for(int j=0;j<lon[0];j++){
	if(a[0][j]==a[2][j]&&a[0][j]==1){
			c[j]==1;
		}
		else{
			c[j]=0;
		}}
		l1=1;
		for(int v=0;v<lon[0];v++){
		if(c[v]==1){
			f=f+l1;
		}
		l1*2;
	}l1=0;
	if(f>=g){
		g=f;
	}
	return 0;
} 
