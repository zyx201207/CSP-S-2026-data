#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int m,n;
	cin>>n>>m;
	int a[n+5];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int d[m+5]={0};
	for(int i=1;i<=n;i++){
		int c[n+5]={0};
		int ii=0;
		for(int j=i-1;j<n;j++){
			for(int k=0;k<n;k++){
				if(c[k]==a[j]){
					ii=k;
					for(int y=k;y<=n;y++)
						c[y]=0;
					break;
				}
			}
			c[ii]=a[j];
			ii++;
		}
		for(int j=1;j<=m;j++){
			for(int k=0;k<n;k++){
				if(c[k]==j){
					d[j]++;
					break;
				}
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<d[i]<<' ';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
