#include <bits/stdc++.h>
using namespace std;
int n,m,i,j,ans[301000],f[501000],a[501000],e[310000];
void sc(int t){
	int i;
	if(t>n){
		for(i=1;i<=m;i++)
			ans[i]+=e[i];
		return ;
	}
	if(f[t]!=0)e[a[t]]=1,sc(f[t]);
	else e[a[t]]=1,sc(t+1);
	e[a[t]]=0;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++)cin>>a[i];
	for(i=n;i>=1;i--)f[i]=e[a[i]],e[a[i]]=i;
	memset(e,0,sizeof e);
	for(i=1;i<=n;i++)
		sc(i);
	for(i=1;i<=m;i++)cout<<ans[i]<<' ';
	return 0;
}
