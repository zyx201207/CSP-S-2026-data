#include <bits/stdc++.h>
using namespace std;
long long n,m,i,k,j,t,a[500010],f[300010],e[300010],b[500010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++)cin>>a[i];
	for(i=1;i<=n;i++){
		t=0;
		for(j=1;j<=m;j++)f[j]=0;
		for(j=i;j<=n;j++)
			if(f[a[j]]==0)f[a[j]]=++t,b[t]=a[j];
			else{
				for(k=f[a[j]]+1;k<=t;k++)f[b[k]]=0;
				t=f[a[j]];
			}
		for(j=1;j<=t;j++)e[b[j]]++;
	}
	for(i=1;i<=m;i++)cout<<e[i]<<" ";
	return 0;
}

