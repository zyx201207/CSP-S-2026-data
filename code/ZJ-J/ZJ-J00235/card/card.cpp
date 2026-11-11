#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<map>
#include<queue>
#include<stack>
#include<cmath>
using namespace std;
int n,m,a[200010],i,j,b[200010],k,s;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	int c[m+10];
	for(i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	for(i=1;i<=n;i++){
		for(j=i;j<=n;j++){
			b[j]=a[j];
		}
		for(j=i;j<=n;j++){
			int q=1;
			for(k=j-1;k>=i;k--){
				if(b[k]==b[j]){
					q=k;
					break;
				}
			}
			if(q==1){
				
			}else{
				for(k=q;k<j;k++){
					b[k]=0;
				}				
			}
		}
		for(j=i;j<=n;j++){
			if(b[j]!=0){
				c[b[j]]++;
			}
		}
	}
	for(i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
	return 0;
}