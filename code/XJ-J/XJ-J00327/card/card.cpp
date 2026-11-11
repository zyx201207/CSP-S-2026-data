#include<bits/stdc++.h>
using namespace std;
int num[300005];
int main(){
	int m,n;
	cin>>n>>m;
	int a[n],b[n][m];
	for(int i=0;i<n;i++){
		cin>>a[i];
		for(int j=0;j<m;j++){
			b[i][j]=a[i];
		}
	}
	for(int g=0;g<m;g++){
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			for(int q=i;q<j;q++){
				if(a[q]==b[j][g]){
					for(int w=q;w<j;w++){
						b[w][g]=-1;
					}
				}
			}
		}
		for(int j=i;j<n;j++){
			if(b[j][g]==g){
				num[g]++;
				break;
		}
		}
}}
	for(int i=0;i<m;i++){
		cout<<num[i]<<" ";
	}return 0;
	}
	