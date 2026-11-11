#include<bits/stdc++.h>
using namespace std;
int n,f=1,m,a[500005],cnt[300005],b[300005],s[300005],vis[300005]; 
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1]){
			f=0;
		}
	}
	if(f==1){
		for(int i=1;i<=m;i++){
			for(int j=i;j<=n;j++){
				if(a[i-1]!=a[i]||j==i){
					cnt[a[i]]++;
				}
			}
		}
		for(int i=1;i<=m;i++){
			cout<<cnt[i]<<" ";
		}
	}
	else{
		for(int i=m;i>=1;i--){
			cout<<i<<" ";
		}
	}
		
	return 0;
} 
