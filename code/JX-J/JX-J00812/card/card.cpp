#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],d[500010],b[300010],c[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			d[j]=a[j];
		}
		for(int j=1;j<=m;j++){
			b[j]=0;
		}
		for(int j=i;j<=n;j++){
			if(b[d[j]]!=0){
				for(int k=j-1;k>=i;k--){
					if(d[k]!=0){
						b[d[k]]=0;
						if(d[k]==d[j]){
							d[k]=0;
							break;
						}
						d[k]=0;
					}
				}
			}
			b[d[j]]=1;
		}
		for(int j=1;j<=m;j++){
			c[j]+=b[j];
		}
	}
	cout<<c[1];
	for(int i=2;i<=m;i++){
		cout<<" "<<c[i];
	}
}
