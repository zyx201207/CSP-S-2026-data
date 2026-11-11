#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500001];
int b[300001];
int c[300001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int k=n;k>=1;k--){
		int t = k;
		memset(c,0,sizeof(c));
		for(int i=k+1;i<=n;i++){
			c[a[i]]++;
		}
		for(int i=k-1;i>=1;i--){
			if(c[a[i]] == 1)c[a[i]]++;
			if(c[a[i]] == 2 && a[i]!=a[k]){
				t--;
			}
		}
		b[a[k]] = max(b[a[k]],t);
	}for(int i=1;i<=m;i++) cout<<b[i]<<' ';
}
