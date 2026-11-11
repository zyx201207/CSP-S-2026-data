#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,ma=0;
	scanf("%d%d",&n,&m);
	int a[n+1];
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			if(a[i]>ma){
				ma=a[i];
			}
		}
		printf("%d",ma);
		return 0; 
	}
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[i]&a[j]>ma){
				ma=a[i]&a[j];
			}
		}
	}
	printf("%d",ma);
	return 0;
}
