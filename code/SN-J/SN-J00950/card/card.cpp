#include<bits/stdc++.h>
using namespace std;
int a[1000010];
int b[1000010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		b[i]=a[i];
	}
	for(int i=1;i<=m;i++){
		int cc=0;
		for(int j=i;j<=n;j++){
			for(int k=j;k<=n;k++){
				if(a[j]==a[k]){
					for(int l=j;l<k;l++){
						b[l]=0;
					}
				}
			}
			for(int q=j;q<=n;q++){
				if(b[q]==i){
					cc++;
				}
			}
			for(int o=1;o<=n;o++){
				b[o]=a[o];
			}
		}
		cout<<cc<<" ";
	}
	return 0;
}
