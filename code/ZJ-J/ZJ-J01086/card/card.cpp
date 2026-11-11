#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int num[3005];
int ans[3005];
int vis[500005];
int f[3005][3005]; 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		num[a[i]]++;
	}
	f[a[n]][a[n]]=1;
	vis[a[n]]=1;
	for(int i=n-1;i>=1;i--){
		if(vis[a[i]]==0){
			vis[a[i]]=1;
			for(int j=1;j<=m;j++) f[a[i]][j]=f[a[i+1]][j];
			f[a[i]][a[i]]=1;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++) ans[j]+=f[i][j]*num[i];
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}
