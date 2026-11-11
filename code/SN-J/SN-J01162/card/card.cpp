#include<bits/stdc++.h>
#include<vector>
using namespace std;
const int N=5e5+10;
int n,m,id=0;
int a[N],b[N];
int c[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int l=1;l<=n;l++){
		id=0;
		memset(c,0,sizeof c);
		for(int i=l;i<=n;i++){
			int flag=0;
			for(int j=1;j<=id;j++){
				if(c[j]==a[i]){
					flag=1;
					for(int k=j;k<=id;k++) c[i]=0;
					id=j;
					c[id]=a[i];
					break;
				}
			}
			if(!flag){
				id++;
				c[id]=a[i];
			}
		}
		int vis[m]={};
		for(int i=1;i<=m;i++){
			b[c[i]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
}
