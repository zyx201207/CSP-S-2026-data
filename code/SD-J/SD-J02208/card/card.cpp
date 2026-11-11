#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[500005],c[300005]; 
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]); 
	}
	for(int i=1;i<=n;i++){
		memset(b,0,sizeof(b));
		int t=0;
		for(int j=i;j<=n;j++){
			b[t+1]=a[j];
			t++;
			c[a[j]]++;
			for(int k=1;k<t;k++){
				if(b[k]==a[j]){
					for(int g=k+1;g<=t;g++){
						c[b[g]]--;
						b[g]=0;
					}
					t=k;
					break;
				}
			}
		}
	}
	for(int i=1;i<=m;i++)  printf ("%d ",c[i]);
	return 0;
}
