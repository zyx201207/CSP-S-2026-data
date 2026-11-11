#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500000+10],b[300000+10],c[300000+10];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(b[a[j]]==0){
				b[a[j]]=j;
			}else{
				for(int k=b[a[j]];k<j;k++){
					if(b[a[k]]>b[a[j]]){
						b[a[k]]=0;
					}
				}
			}
		}
		for(int j=1;j<=m;j++){
			if(b[j]!=0){
				c[j]++;
			}
		}for(int j=1;j<=m;j++){
			b[j]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<' ';
	}
	return 0;
}
