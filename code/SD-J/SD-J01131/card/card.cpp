#include<bits/stdc++.h>
using namespace std;
long long n,m,a[510000],ans[310000],vis[310000];
bool flag;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		long long lst=i;
		for(int j=i+1;j<=n;j++){
			if(a[j]==a[lst]){
				lst=j;
				j++;
			}
		}
		memset(vis,0,sizeof vis);
		for(int j=lst;j<=n;j++){
			cout<<a[j]<<" ";
			if(!vis[a[j]]){
				ans[a[j]]++;
				vis[a[j]]=1;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
