#include <bits/stdc++.h>
using namespace std;
int n,m,i,j,k,f[300100],a[500100],ans[300100],st[500100],t;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(i=1;i<=n;i++)cin>>a[i];
	for(i=1;i<=n;i++){
		memset(f,0,sizeof(f));
		memset(st,0,sizeof(st));
		t=0;
		for(j=i;j<=n;j++){
			if(f[a[j]]!=0){
				while(st[t]!=a[j])f[st[t]]=0,t--;
				f[a[j]]=j;
			}
			else t++,st[t]=a[j],f[a[j]]=j;
		}
		for(j=1;j<=n;j++)
			if(f[a[j]]==j)ans[a[j]]++;
	}
	for(i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
}