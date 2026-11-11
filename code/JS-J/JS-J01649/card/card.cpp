#include<bits/stdc++.h>
using namespace std;
int a[500005];
int c[500005];
int b[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n-i+1;j++){
			for(int k=1;k<=305;k++){
				if(c[k]==0||c[k]==-1){
					c[k]=a[j];
					break;
				}
			}
		}
		for(int j=1;j<=m;j++){
			int pos=0;
			for(int k=1;k<=500005;k++){
				if(k>j&&c[k]==a[j]){
					pos=j;
					break;
				}
			}
			for(int k=pos;k>=1;k--){
				if(k==pos){
					c[k]=-1;
				}
				if(k!=pos&&c[k]!=a[j]){
					c[k]=-1;
				}
				if(c[k]==a[j]&&k!=pos){
					break;
				}
			}
		}
		
		for(int j=1;j<=1000;j++){
			if(c[j]!=-1){
				b[c[j]]++;
			}
			
		}
		for(int j=1;j<=m;j++){
			cout<<b[j]<<" ";
		}
		cout<<endl;
	}
	
	return 0;
}
