#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[10000005];
int b[10000005];
int c[10000005];
int d[10000005];
int e=0;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[i]==a[j]){
				for(int k=i+1;k<=j;k++){
					b[k]=0;
				}
			}
			if(b[j]!=0){
				c[j]=b[j];
			}
		}
		for(int j=i;j<=n;j++){
			if(c[j]!=0){
			int e=char(c[j])-48;
			d[e]+=1;
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(d[i]!=0){
			cout<<d[i]<<" ";
		}
	}
	return 0;
}
