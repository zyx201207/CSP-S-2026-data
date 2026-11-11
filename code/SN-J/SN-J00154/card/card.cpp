#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card .out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n+5];
	int b[m];
	for(int i=0;i<m;i++){
		b[i]=0;
	}
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	bool op=true;
	for(int i=0;i<n;i++){
		if(a[i]<a[i+1]||a[i]==a[i+1]){
			op=true;
		}else{
			op=false;
			break;
		}
	}
	int k[n][n];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			k[i][j]=0;
		}
		for(int j=i;j<n;j++){
			k[i][j]=a[j];
		}
	}
	if(op=true){
		for(int i=0;i<n;i++){
			for(int j=i;j<n;j++){
				if(k[i][j]=k[i][j+1]){
					k[i][j]=0;
				}
			}
			for(int j=0;j<n;j++){
				if(k[i][j]!=0){
					b[k[i][j]-1]++;
				}
			}
		}
		for(int i=0;i<m;i++){
			cout<<b[i]<<' ';
		}
	}
	bool ip=true;
	for(int i=0;i<n;i++){
		if(a[i]!=a[i+1]){
			ip=true;
		}else{
			ip=false;
			break;
		}
	}
	if(ip=true){
		for(int i=0;i<m;i++){
			cout<<i+1;
		}
	}
	return 0;
}
