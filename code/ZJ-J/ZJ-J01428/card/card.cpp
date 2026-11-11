#include<bits/stdc++.h>
using namespace std;
int a[10001],b[10001][10001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			for(int k=j;k>=i,b[i][k]!=1;k--){
				if(a[k]==a[j]){b[i][k]=1;b[i][k]=2;}
			}
		}
	}
	int z=1;
	int ans[m+1]={0};
	for(int j=1;j<=n;j++){
		for(int k=j;k<=n;k++){
			if(b[j][k]==2)z=2;
			if(b[j][k]==1)z=1;
			if(z=1&&b[j][k]==0)ans[a[k]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i];
	}
	return 0;
} 
