#include<bits/stdc++.h>
using namespace std;
int a[500010],b[300010],c[500010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(j+i<=n) {
				c[i]=a[j+i-1];
				for(int k=1;k<=j;k++){
					if(c[j]==c[k]){
						for(int t=j+1;t<=j;t++){
							c[t]=0;
						}
					}
				}
			}
		}
		for(int j=1;j<=m;j++){
			b[c[j]]++;
		}
		for(int j=1;j<=m;j++){
			cout<<b[j]<<" ";
		}
		cout<<i<<" "<<endl;
		for(int j=1;j<=n;j++){
			c[j]=0;
		}
	}
}
