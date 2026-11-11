#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5,M=3e5+5;
int a[N],n,m;
int t[M],tt[M],sum[M];
bool vis[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		tt[a[i]]++;
		if(a[i]!=a[i-1]){
			sum[a[i]]=sum[a[i-1]]+tt[a[i]];
		}
	}
	if(n>500){
		for(int i=1;i<=m;i++){
			if(tt[i]%2==0){
				cout<<sum[i-1]<<" ";
			}
			else{
				cout<<sum[i-1]+1<<" ";
			}
		}
		return 0;
	} 
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof(vis));
		for(int j=i;j<=n;j++){
			int las=0;
			for(int k=j-1;k>=i;k--){
				if(vis[k]==1) continue;
				if(a[k]==a[j]){
					las=k;
					break;
				}
			}
			if(las!=0){
				for(int k=las;k<j;k++){
					vis[k]=1;
				}
			}
		}
		for(int j=i;j<=n;j++){
			if(vis[j]==0){
				t[a[j]]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<t[i]<<" ";
	}
	return 0;
}
