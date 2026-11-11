#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int N=5e5+2,M=3e5+2;
int n,m;
int tong[M];
int a[N];
int vis[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i]; 
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){	
			if(!vis[a[j]])vis[a[j]]=j;
			else{
				for(int k=vis[a[j]];k<j;k++){
					vis[a[k]]=0;
				}
				vis[a[j]]=j;
			}
		}
		for(int k=1;k<=m;k++){
			if(vis[k]){
				tong[k]++;
				vis[k]=0;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<tong[i]<<" ";
	}
	return 0;
}
