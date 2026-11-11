#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],s,b[500010],p,i,f[200010],j,vis[500010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++)cin>>a[i];
	if(m==2){
		for(i=1;i<=n;i++)f[a[i]]++;
		if(a[n]==1)cout<<n<<" "<<f[2];
		else cout<<f[1]<<" "<<n;
		exit(0);
	}
	for(i=1;i<=n;i++){
		s=0;p=0;
		memset(f,0,sizeof(f));
		for(j=i;j<=n;j++){
			if(!f[a[j]])b[++p]=a[j],f[a[j]]=p;
			else if(f[a[j]]<=p){
				b[f[a[j]]]=a[j];
				p=f[a[j]];
			}
			else b[++p]=a[j],f[a[j]]=p;
		}
		for(j=1;j<=p;j++)
			vis[b[j]]++;
	}
	for(i=1;i<=m;i++)cout<<vis[i]<<" ";
	return 0;
}
