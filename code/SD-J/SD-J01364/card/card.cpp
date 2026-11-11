#include<bits/stdc++.h>
using namespace std;
const int N=5e5;
int a[N],ans[N],b[N],vis[N];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m; 
	bool f=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1])f=1;
	}
	if(!f){
		int cnt=1;
		for(int i=1;i<=n;i++){
			if(a[i]!=a[i+1])cout<<cnt<<" ";
			cnt++;
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		int cnt=0;
		for(int j=1;j<=m;j++)vis[j]=0;
		for(int j=i;j<=n;j++){
			if(vis[a[j]]>0){
				for(int k=vis[a[j]]+1;k<=cnt;k++)vis[b[k]]=0; 
				cnt=vis[a[j]]-1;
			}
			b[++cnt]=a[j];
			vis[a[j]]=cnt;
		}
		for(int j=1;j<=cnt;j++)ans[b[j]]++; 
	}
	for(int j=1;j<=m;j++){
		cout<<ans[j]<<" ";
	}
	return 0;
}
/*
10 3
3 1 2 1 3 2 3 1 2 1


*/

