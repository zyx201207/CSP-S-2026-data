#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n+1];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int c[m+1]={0};
	for(int i=1;i<=n;i++){
		int b[n+1]={0};
		for(int j=i;j<=n;j++){
			bool y=0;
			int u=0;
			for(int z=1;z<=n;z++){
				if(b[z]==a[j]){
					y=1;
					u=z;
					continue;
				}
			}
			if(y==0){
				b[j]=a[j];
			}else{
				for(int z=u+1;z<n;z++){
					b[z]=0;
				}
			}
		}
		for(int j=1;j<=n;j++){
			c[b[j]]++;
		}
	}
	for(int i=1;i<m;i++){
		cout<<c[i]<<" ";
	}
	cout<<c[m];
	return 0;
}
