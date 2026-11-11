#include<bits/stdc++.h>
using namespace std;
const int N=2e5+20;
int n,m;
int a[N],lst[N],ans[N],nxt[N],vis[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=n;i>=1;i--){
		if(!lst[a[i]]){
			lst[a[i]]=i;
		}
	}
	for(int i=1;i<=n;i++){
		if(lst[a[i]]!=i){
			nxt[i]=lst[a[i]];
		}
	}
	for(int i=1;i<=n;i++){
		int j=i;
		while(j<n){
			if(nxt[j]==0){
				ans[a[j]]++;
				j++;
			}
			else{
				j=nxt[j];
			}
		}
		ans[a[j]]++;
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
} 
//Trick||Treat!
/*
10 3
3 1 2 1 3 2 3 1 2 1
*/
