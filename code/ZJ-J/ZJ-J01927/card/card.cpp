#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005],ans[300005],t[300005],nxt[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		nxt[t[a[i]]]=i;
		t[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(nxt[j]!=0){
				j=nxt[j]-1;
				continue;
			}
			ans[a[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
