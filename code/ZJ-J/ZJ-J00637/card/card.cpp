#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int b[n];
	int s[m+1];
	memset(s,0,sizeof(s));
	for(int i=0;i<n;i++){
		int x=0;
		for(int j=i;j<n;j++){
			b[x]=a[j];
			for(int y=x-1;y>=0;y--){
				if(b[y]==b[x]){
					x=y;
					break;
				}
			}
			x++;
		}
		bool vis[m+1];
		memset(vis,0,sizeof(vis));
		for(int j=0;j<x;j++){
			vis[b[j]]=1;
		}
		for(int j=1;j<=m;j++){
			if(vis[j]){
				s[j]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<s[i]<<' ';
	}
	return 0;	
}
