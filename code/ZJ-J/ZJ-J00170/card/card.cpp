#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,i,j,k,a[500010],f[300010],e[300010],g[300010];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin>>n>>m;
	for(i=1;i<=n;i++) cin>>a[i];
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++) f[j]=e[j]=0;
		for(j=i;j<=n;j++){
			if(f[a[j]]+1==2){
				for(k=e[a[j]];k<j;k++) if(f[a[k]]) f[a[k]]--;
			}
			f[a[j]]++;e[a[j]]=j;
		}
		for(j=1;j<=m;j++)
			if(f[j]>0) g[j]++;
	}
	for(i=1;i<=m;i++) cout<<g[i]<<" ";
	return 0;
}