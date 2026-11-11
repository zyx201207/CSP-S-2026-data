#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,i,a[2000010],t,w,f[2000010],js[2000010],j,x,k;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin>>n>>m;
	for(i=1;i<=n;i++) cin>>a[i];
	for(i=1;i<=n;i++){
		t=w=1;
		f[w]=a[i];
		for(j=i+1;j<=n;j++){
			for(k=t;k<=w;k++)
			  if(f[k]==a[j]) break;
			if(k>w) f[++w]=a[j];
			else w=k-1,f[++w]=a[j];
		}
		for(j=t;j<=w;j++)
		  js[f[j]]++;
	}
	for(i=1;i<=m;i++) cout<<js[i]<<" ";
	return 0;
}
/*
Trick||Treat!
4 3
1 2 1 3
*/