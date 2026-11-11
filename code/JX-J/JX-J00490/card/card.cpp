#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[505],b[505],bi,op,c[505],d[505],tot;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	if(n<=500){
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			bi=0;
			memset(b,0,sizeof(b));
			memset(c,0,sizeof(c));
			for(int j=i;j<=n;j++){
				for(int k=1;k<=bi;k++){
					if(b[k]==a[j]){
						bi=k;
						op=1;
						for(int l=k+1;l<=bi;l++){
							b[l]=0;
						}
					}
					if(op==1){
						break;
					}
				}
				if(op==0){
					bi++;
					b[bi]=a[j];
				}op=0;
			}
			for(int j=1;j<=bi;j++){
				c[b[j]]=1;
			}
			for(int j=1;j<=m;j++){
				d[j]+=c[j];
			}
		}
		for(int i=1;i<=m;i++){
			cout<<d[i]<<" ";
		}
		return 0;
	}
}
