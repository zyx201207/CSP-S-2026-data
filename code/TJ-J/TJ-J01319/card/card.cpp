#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,a[5001],c[5001],tong1[3001],tong2[3001],tong3[3001];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		tong2[i]=0;
	}
	for(int i=1;i<=n;i++){
		int h=1;
		for(int y=1;y<=m;y++){
			tong1[y]=0;
			tong3[y]=0;
			c[y]=0;
		}
		for(int j=i;j<=n;j++){
			if(tong1[a[j]]==1){
				h=tong3[a[j]];
				c[h]=a[j];
			}else{
				c[h]=a[j];
				h++;
				tong1[a[j]]=1;
				tong2[c[h]]++;
				tong3[c[h]]=j;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<tong2[i]<<" ";
	}
	return 0;
}
