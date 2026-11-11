#include<bits/stdc++.h>
#define int long long
#define FIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;
int t[300005],tt[300005],vis[500005],fi[300005],la[300005],a[500005];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	FIO
	int n,m,i,j,k;
	cin>>n>>m;
	for(i=1;i<=n;i++)
		cin>>a[i];
	for(i=1;i<=n;i++){
		for(j=1;j<=i;j++) vis[j]=0;
		for(j=1;j<=i;j++)
			if(!t[a[j]]) t[a[j]]=1,fi[a[j]]=j;
		for(j=1;j<=m;j++) t[j]=0;
		for(j=i;j>=1;j--)
			if(!t[a[j]]) t[a[j]]=1,la[a[j]]=j;
		for(j=1;j<=m;j++){
			for(k=fi[j]+1;k<=la[j];k++) vis[k]=1;
		}
		for(j=1;j<=i;j++)
			if(!vis[j]) tt[a[j]]++;
	}
	for(i=1;i<=m;i++) cout<<tt[i]<<' ';
	return 0;
}