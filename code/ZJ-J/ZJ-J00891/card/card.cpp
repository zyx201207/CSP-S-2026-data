#include<bits/stdc++.h>
using namespace std;
int n,m,i,j,t,a[500100],c[500100],e[300100];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++){
		cin>>a[i];c[a[i]]=i;
	}for(i=1;i<=n;i++){
		for(j=i;j<=n;j++){
			e[a[j]]++;j=c[a[j]];
		}
	}for(i=1;i<=m;i++){
		cout<<e[i]<<" ";
	}return 0;
}
