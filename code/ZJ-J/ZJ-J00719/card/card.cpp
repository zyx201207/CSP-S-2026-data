#include<bits/stdc++.h>
using namespace std;
const int N=500005;
int n,m,sum;
int a[N];
int ee[300005];
int c[N],tt;
int d[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++) d[j]=0;
		tt=0;
		for(int j=i;j<=n;j++) {
			if(d[a[j]]==0){
				d[a[j]]=++tt;
				c[tt]=a[j];
			}
			else{
				for(int k=tt;k>d[a[j]];k--){
					d[c[k]]=0;
					tt--;
				}
			}
		}
		for(int j=1;j<=tt;j++) {
			ee[c[j]]++;
		}
	}
	for(int i=1;i<=m;i++) printf("%d ",ee[i]);
	return 0;
}
