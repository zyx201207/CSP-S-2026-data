#include<bits/stdc++.h>
using namespace std;
const int N=5*100000+10,M=3*100000+10;
int n,m;
int a[N],ii[M];
int ifind(int b[N],int y){
	for(int i=0;i<n;i++){
		if(b[i]==y){
			return i;
		}
	}
	return -1;
}
int x[N];
int iback(int z,int zz){
	for(int i=z;i<n+10;i++){
		x[i]=0;
	}
	x[z]=zz;
	return 0;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		
		for(int j=i;j<n;j++){
			if(ifind(x,a[j])!=-1){
				iback(ifind(x,a[j]),a[j]);
			}else{
				x[j]=a[j];
			}
		}
		for(int j=1;j<=m;j++){
			if(ifind(x,j)!=-1){
				ii[j]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ii[i]<<' ';
	}
	return 0;
}