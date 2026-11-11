#include<bits/stdc++.h>
using namespace std;
int a[100005],b[100005][100005];
int main(){
freopen("card.in","r",stdin);
freopen("card.out","w",stdout);
int n,m;
int d[100005];
cin>>n>>m;
for(int i=1;i<=n;i++){
	cin>>a[i];
	}
for(int i=1;i<=n;i++){
	for(int j=i;j<=n;j++){
	b[i][j]=a[i];
	for(int k=1;k<j;k++){
	if(b[i][j]==b[i][k]){
		for(int h=k;h<j;h++){
		b[i][h]=0;
	}
}
	}}
}
for(int i=0;i<=n;i++){
	for(int j=1;j<=n;j++){
		for(int l=1;l<=m;l++){
		if(b[i][j]==l) d[l]=d[l]+1;
	}
		}
	}
	for(int l=1;l<=m;l++)
	cout<<d[l];
	return 0;
}
