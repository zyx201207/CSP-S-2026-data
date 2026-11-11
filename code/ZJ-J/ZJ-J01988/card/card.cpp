#include<bits/stdc++.h>
using namespace std;
int n,m,k=1;
int a[500005],b[500005],c[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	int n2=n;
	while(n--){
		k=1;
		for(int i=n2-n;i<=n2;i++){
			int f=1,f2;
			for(int j=1;j<k;j++){
				if(b[j]==a[i]){
					f2=j;
					f=0;
					break;
				}
			}
			if(f){
				b[k]=a[i];
				k++;
			}else{
				k=f2+1;
			}
		}
		for(int i=1;i<k;i++){
			c[b[i]]++;
		}
	}
	c[a[n2]]=n2;
	for(int i=1;i<=m;i++)printf("%d ",c[i]);
	
	return 0;
}
