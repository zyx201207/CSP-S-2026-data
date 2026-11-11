#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5,M=1e3+5;
int n,m,a[N],b[N],vis[N],t[N]; 
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(b,0,sizeof(b));
		memset(vis,0,sizeof(vis));
		for(int j=i;j<=n;j++){
			if(!vis[a[j]]){
				b[j]=a[j];
				vis[a[j]]=1;
			}else{
				vis[b[j]]=0;
				b[j]=0;
				for(int k=j-1;k>=1;k--){
					if(b[k]==a[j]){
						break;
					}
					vis[b[k]]=0;
					b[k]=0;
				}
			}
		}
		for(int j=1;j<=n;j++){
			if(b[j]!=0)t[b[j]]++;
		}
	}
	for(int j=1;j<=m;j++){
		cout<<t[j]<<" ";
	}
	return 0;
}

