#include<bits/stdc++.h>
using namespace std;
int n,m,i,j,k,t,b[500010],a[500010],f[300010],w;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin>>n>>m;
	for(i=1;i<=n;i++) cin>>a[i];
	for(i=1;i<=n;i++){
		t=0;
		memset(b,0,sizeof(b));
		for(j=i;j<=n;j++){
			b[++t]=a[j];
			for(k=t-1;k>=1;k--){
				if(b[k]==b[t]){
					t=k;
					b[t]=a[j];
					break;
				}
			}
		}
		for(j=1;j<=t;j++){
			f[b[j]]++;
		}
	}
	for(i=1;i<=m;i++) cout<<f[i]<<' ';
	return 0;
}
