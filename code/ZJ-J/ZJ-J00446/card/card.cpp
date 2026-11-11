#include <bits/stdc++.h>
using namespace std;
int n,m,t[3005],a[500005],ans[300005],sum[3005];
bool vis[300005],ca[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	/*
	if (n>200000){
		
		return 0;
	}*/
	for (int i=1;i<=n;++i){
		cin>>a[i];/*
		for (int j=1;j<=m;++j){
			if (a[i]==j){
				qz[j][i]=qz[j][i-1]+1;
			}else {
				qz[j][i]=qz[j][i-1];
			}
		}*/
	}
	
	for (int i=1;i<=n;++i){
		memset(t,-1,sizeof(t));
		memset(vis,false,sizeof(vis));
		memset(ca,false,sizeof(ca));
		/*int l,r;
		for (int k=1;k<=m;++k){
			sum[k]=qz[k][n]-qz[k][i-1];
		}*/
		for (int j=i;j<=n;++j){
			if (t[a[j]]==-1){
				t[a[j]]=j;
			}else {
				if (vis[t[a[j]]]){
					t[a[j]]=j;
				}else {
					for (int k=t[a[j]];k<=j-1;++k){
						vis[k]=true;
					}
					t[a[j]]=j;
				}
			}
		}
		for (int j=i;j<=n;++j){
			if (!vis[j]){
				ca[a[j]]=true;
			}
		}
		for (int j=1;j<=m;++j){
			if (ca[j]){
				ans[j]++;
			}
		}
	}
	for (int i=1;i<=m;++i){
		cout<<ans[i]<<" ";
	}
	return 0;
}