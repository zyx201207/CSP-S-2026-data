#include<bits/stdc++.h>
using namespace std;
int n,m,a[900005],nxt[900005],t[900005],ans[900005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=n;i;i--){
		if(!t[a[i]]) t[a[i]]=i;
		else nxt[i]=t[a[i]],t[a[i]]=i;
	}for(int i=0;i<n;i++){
		int j=i+1;
		while(j<=n){
			while(nxt[j]) j=nxt[j];
			ans[a[j]]++,j++;
		}
	}for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
}