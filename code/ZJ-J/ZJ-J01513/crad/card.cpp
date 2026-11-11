#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500000+10],vis[500000+10],pos[500000+10];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		pos[a[i]]=max(pos[a[i]],i);
	}
	for(int i=1;i<=n;i++){
		vis[a[i]]++;
		int j=pos[a[i]]+1;
		for(;j<=n;j++){
			vis[a[j]]++;
			if(pos[a[j]]!=j){
				j=pos[a[j]];
			}	
		}
	}
	for(int i=1;i<=m;i++){
		cout<<vis[i]<<" ";
	}
	return 0;
}