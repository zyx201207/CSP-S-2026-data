#include<bits/stdc++.h>
using namespace std;
int a[1000005],b[1000005];
int main(){
	//freopen("card.in","r",stdin);
	//freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		bool c[1000004];
		int d[1000005];
		for(int j=0;j<=n+5;j++){
			c[i]=0;
			d[i]=0;
		}
		for(int j=i;j<=n;j++){
			if(c[a[j]]==0){
				c[a[j]]=1;
				d[a[j]]=j;
			}
			if(c[a[j]]==1){
				for(int l=d[a[j]]+1;l<=j;l++){
					c[a[l]]=0;
				}
				d[a[j]]=j;
			}
		}
		for(int j=i;j<=n;j++){
			if(c[a[j]]==1){
				b[a[j]]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i];
	}
	return 0;
} 
