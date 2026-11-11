#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500100],vis[300100],sum[300100];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int k=i;k<=n;k++){
			if(vis[a[k]]!=0){
				for(int j=vis[a[k]];j<=k;j++)vis[a[j]]=0;
			}
			vis[a[k]]=k;
		}
		for(int j=1;j<=m;j++){
			if(vis[j]!=0)sum[j]++;
			vis[j]=0;
		}
	}
	for(int i=1;i<=m;i++)cout<<sum[i]<<" ";
	return 0;
}
/*
10 3
3 1 2 1 3 2 3 1 2 1
*/
//I will become better!
