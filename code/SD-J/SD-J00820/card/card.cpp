#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500010];
int ans[300010];
int q[300010];
int tong[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(tong[a[i]]){
			q[tong[a[i]]]=i;
		}
	}
	for(int x=1;x<=n;x++){
		int i=x;
		for(int jj=0;jj<=m;jj++){
			tong[jj]=0;
		}
		while(i<=n){
			if(tong[a[i]]==0)
				ans[a[i]]++;
			tong[a[i]]=1;
			while(q[i]){
				i=q[i];
			}
			i++;
		}
		
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
} 
