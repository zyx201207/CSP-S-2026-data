#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int zhan[500005];
int box[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int l=1,r=1;
		for(int j=i;j<=n;j++){
			for(int z=l;z<=r-1;z++){
		 		if(zhan[z]==a[j]){
		 			r=z;
		 			break;
				}
		 	}
			zhan[r++]=a[j];
		}
		for(int z=l;z<r;z++){
			box[zhan[z]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<box[i]<<" ";
	}
	return 0;
} 
