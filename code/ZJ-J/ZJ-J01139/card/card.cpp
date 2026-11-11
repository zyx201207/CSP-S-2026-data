#include<bits/stdc++.h>
using namespace std;
int n,m,tot,st,a[500005],b[500005],p[500005],f[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=n;j>i;j--){
			if(a[j]==a[i]){
				p[i]=j;
				break;
			}
		}
	}
	for(int i=1;i<=n;i++){
		tot=0;
		for(int j=i;j<=n;){
			if(p[j]==0) b[++tot]=a[j],j++;
			else j=p[j];
		}
		for(int j=1;j<=tot;j++) f[b[j]]++;
	} 
	for(int i=1;i<=m;i++) cout<<f[i]<<" ";
	return 0;
}