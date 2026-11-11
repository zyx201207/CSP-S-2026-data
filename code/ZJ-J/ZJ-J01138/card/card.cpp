#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,i,j,k,l,x,t,z,s,d,g,h,a[500100],r[500100],f[500100],e[500100];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++) cin>>a[i];
	for(i=1;i<=n;i++){
		for(j=i;j<=n;j++)
			if(f[a[j]]==1){
				for(k=e[a[j]]+1;k<=j-1;k++)
					f[a[k]]=0;
				e[a[j]]=j;
			}
			else{
				f[a[j]]=1;
				e[a[j]]=j;
			}
		for(j=1;j<=m;j++) r[j]+=f[j],f[j]=0;
	}
	for(i=1;i<=m;i++)
		cout<<r[i]<<" ";
	return 0;
}