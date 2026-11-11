#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			a[i]=b[i];
		}
		for(int j=i;j<=n;j++){
			int wei=0;
			for(int z=1;z<=j-1;z++){
				if(a[z]==a[j]){
					wei=z;
					break;
				}
			}
			for(int z=wei;z<j;z++){
				a[i]=0;
			}
		}
		for(int j=i;j<=n;j++){
			if(a[j]==i){
				printf("%d ",i);
				break;
			}
		}
	}
	cout<<n;
	return 0;
}
