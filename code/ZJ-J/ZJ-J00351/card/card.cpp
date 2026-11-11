#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n+1],bb[n+1],c[n+1];
	for(int i=1; i<=n; i++) {
		bb[i]=0;
		c[i]=0;
		cin>>a[i];
	}
	for(int i=1; i<=n; i++) {
		int k=0;
		for(int j=1; j<=n+1; j++) c[j]=0;
		for(int j=i; j<=n; j++) {
			bool b=1;
			int biao;
			for(int u=k; u>=1; u--) {
				if(a[j]==c[u]) {
					b=0;
					biao=u;
					break;
				}
			}
			if(b==0) {
//				cout<<biao<<endl;
				for(int u=biao; u<=k; u++)
					c[u]=0;
			}
			k++;
			c[k]=a[j];
		}
//		for(int j=1; j<=k; j++) cout<<c[j]<<" ";
//		cout<<endl;
		for(int j=1; j<=k; j++) {
			bb[c[j]]++;
		}
//		for(int i=1; i<=m; i++) cout<<bb[i]<<" ";
//		cout<<endl;
	}
	for(int i=1; i<=m; i++) cout<<bb[i]<<" ";
	return 0;
}/* 10 3
3 1 2 1 3 2 3 1 2 1*//*
嵊州市新城实验学校909，ZHY LOVE ZZQ
我的洛谷:yeweibo
*/
