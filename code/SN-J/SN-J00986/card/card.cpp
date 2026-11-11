#include<bits/stdc++.h>
using namespace std;
int a[500005];
int b[500005];
int c[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int o=1;
		for(int j=i;j<=n;j++){
			for(int k=1;k<=o;k++){
				if(b[k]==a[j]){
					o=k;
					break;
				}
			}
			b[o]=a[j];
			o++;
		}
		for(int k=1;k<=m;k++){
			for(int j=1;j<=o-1;j++){
				if(b[j]==k){
					c[k]++;
					break;
				}
			}
		}
		
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
	
	return 0;
}
