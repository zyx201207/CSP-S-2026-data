#include<bits/stdc++.h>
using namespace std;
long long a[10000091],c[1000001],lo[1000001][3],m,n;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			lo[j][1]=0;
		}
			for(int j=i;j<=n;j++){
			lo[a[j]][1]++;
			if(lo[a[j]][1]>1){
				for(int k=lo[a[j]][2];k<j;k++){
					lo[a[k]][1]--;
				}
			}
			if(lo[a[j]][1]==1){
				lo[a[j]][2]=j;
			}
		}
		for(int j=1;j<=m;j++){
			if(lo[j][1]!=0){
				c[j]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
	return 0;
}