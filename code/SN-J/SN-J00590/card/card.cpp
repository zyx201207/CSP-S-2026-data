#include<bits/stdc++.h>
using namespace std;
int n,m,a[100000],b[100000],a1[100000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m); 
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		a1[i]=a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			for(int k=i;k<j;k++){
				if(a[k]==a[j]){
					a[k]=a[j];
					for(int l=k+1;l<=j;l++){
						a[l]=0;
					}	
					break;
				}
			}
		}
		for(int j=i;j<=n;j++){
			b[a[j]]++;
		}
		for(int i=1;i<=n;i++){
			a[i]=a1[i];
		}
	}
	for(int i=1;i<=m;i++){
		printf("%d",b[i]);
		printf("%c",' ');
		}
	return 0; 
}
//这题如果能得二十分都算幸运了 TVT 
