#include <bits/stdc++.h>
using namespace std;
int n,m,i,t,a[500010],f[500010],g[500010];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++){
		cin>>a[i];
		g[a[i]]=i;
	}
	for(i=1;i<=n;i++)
	for(i=1;i<=n;i++){
		t=i;
		while(t<=n){
			if(g[a[t]]!=0&&g[a[t]]!=t) t=g[a[t]];
			f[a[t]]++;t++;
		}
	}
	for(i=1;i<=m;i++) cout<<f[i]<<" ";
}
