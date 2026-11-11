#include <bits/stdc++.h>
#pragma GCC optimize("O1")
#pragma GCC optimize("O2")
#pragma GCC optimize("O3")
#pragma GCC optimize("O4")
#pragma GCC optimize("O5")
#pragma GCC optimize("Os")
#pragma GCC optimize("Og")
#pragma GCC optimize("Ofast")
#pragma G++ optimize("O1")
#pragma G++ optimize("O2")
#pragma G++ optimize("O3")
#pragma G++ optimize("O4")
#pragma G++ optimize("O5")
#pragma G++ optimize("Os")
#pragma G++ optimize("Og")
#pragma G++ optimize("Ofast")
#define int long long
using namespace std;
int n,m,i,j,k,t,fl,a[500010],f[500010],e[500010];
main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1]) fl=1;
	}
	if(!fl){
		for(i=1;i<=n;i++) e[a[i]]++;
		for(i=1;i<=m;i++) e[i]+=e[i-1],cout<<e[i]<<" ";
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++) f[j]=0;t=0;
		for(j=i;j<=n;j++)
			if(!f[a[j]]) f[a[j]]=++t;
			else{
				for(k=1;k<=m;k++)
					if(f[k]>f[a[j]]) f[k]=0,t--;
			}
		for(j=1;j<=m;j++)
			if(f[j]) e[j]++;
	}
	for(i=1;i<=m;i++) cout<<e[i]<<" ";
	return 0;
}
