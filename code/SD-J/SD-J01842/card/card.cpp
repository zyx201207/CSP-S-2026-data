#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define endl '\n'
ll n,m,a[500005],ans[300005],vis[500005];
bool xa=1;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		if (a[i-1]>a[i]) xa=0;
	}
	if (xa){
		a[n+1]=1e9+7;
		for (int i=1;i<=n;i++){
			if (a[i+1]>a[i]){
				ans[a[i]]=i;
			}
		}
		for (int i=1;i<=m;i++) cout<<ans[i]<<' ';
		return 0;
	}
	for (int i=1;i<=n;i++){
		for (int j=i;j<=n;j++){
			int l=-1;
			for (int k=j-1;k>=i;k--){
				if (vis[k]) continue;
				if (a[k]==a[j]){
					l=k;
					break;
				}
			}
			if (l==-1) continue;
			for (int k=l;k<j;k++){
				vis[k]=1;
			}
		}
		for (int j=i;j<=n;j++){
			if (!vis[j]){
				ans[a[j]]++;
			}
		}
		for (int j=i;j<=n;j++) vis[j]=0;
	}
	for (int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
} 
