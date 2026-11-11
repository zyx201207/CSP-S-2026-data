#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n],b[m]={0};
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int c[n];
	for(int l=0;l<n;l++){
		for(int i=l;i<n;i++){
		c[i]=a[i];
		for(int j=0;j<i;j++){
			if(c[j]=c[i]){
				for(int k=j;k<i;k++){
					c[k]=0;
				}
			}
		}
		for(int r=0;r<n;r++){
			if(c[r]!=0){
				b[c[r]-1]=0;
				c[r]=0;
			}
		}
	}
	}
	for(int i=0;i<m;i++){
		cout<<c[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
