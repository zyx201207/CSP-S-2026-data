#include<bits/stdc++.h>
using namespace std;
int a[500100],f[500100],nt[500100],ans[300100],b[300100];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m,i,j;
	cin>>n>>m;
	for(i=1;i<=n;i++) cin>>a[i],nt[i]=i+1,f[i]=1;
	for(i=n;i>=1;i--){
		if(b[a[i]]) nt[i]=b[a[i]];
		b[a[i]]=i;
	}
	for(i=1;i<n;i++) f[nt[i]]+=f[i];
	for(i=n;i>=1;i--) if(ans[a[i]]==0) ans[a[i]]=f[i];
	for(i=1;i<=m;i++) cout<<ans[i]<<' ';
	return 0;
} 

