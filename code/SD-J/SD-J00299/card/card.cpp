#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
const int M=3e5+5;
int n,m;
int a[N],ans[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int t=1;
	while(t<=n){
		int vis[M];
		memset(vis,0,sizeof vis);
		for(int i=t;i<=n;i++){
			if(vis[a[i]]){
				for(int j=i-1;a[j]!=a[i];j--){
					if(vis[a[j]]) vis[a[j]]--;
				}
				vis[a[i]]--;
			}
			vis[a[i]]++;
		}
		for(int i=1;i<=m;i++){
			if(vis[i]){
				ans[i]++;
			}
		}
		t++;
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}

