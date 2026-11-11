#include<bits/stdc++.h>
using namespace std;
int a[500000],b[500000],c[500000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
    for(int j=1;j<=n;j++){b[i]=a[i];}}
    for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			for(int k=1;k<=j;k++){
				if(b[k]==b[j]){
					for(int u=k;u<=j;u++){
						b[u]=0;
					}
					}
				}
			}
		}
		for(int o=1;o<=n;o++){
			c[b[o]]++;
		for(int q=1;q<=n;q++){b[q]=a[q];}
		}
	

	for(int i=1;i<=m;i++){cout<<c[i]<<" ";}}

