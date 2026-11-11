#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200100],vis[300100],ans[300100];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	for(long long i=1;i<=n;i++){
		for(long long j = i;j<=n;j++){
			if(vis[a[j]] == 0){
				vis[a[j]] = j;
			}
			else{
				for(long long k = vis[a[j]];k<j;k++){
					vis[a[k]] = 0;
				}
				vis[a[j]] = j;
			}
		}
		for(long long j = 1;j<=m;j++){
			if(vis[j] != 0)ans[j] ++;
			vis[j] = 0;
		}
		for(long long j = 1;j<=n;j++){
			a[j] = abs(a[j]);
		}
	}
	for(long long i = 1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
