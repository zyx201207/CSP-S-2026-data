

#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m;
int a[N],b[N],c[N];
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		c[i]=a[i];
		for(int j=i;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				if(c[k]==c[j]){
					j=k-1;
					for(int l=1;l<=j;l++){
						c[l]=0;
					}
				}
			}
			if(c[j]!=0){
				for(int r=j;r<=n;r++){
					b[c[r]]++;
				}
			}
		}
	}
	b[a[n]]=n;
	b[a[1]]+=1;
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
}

