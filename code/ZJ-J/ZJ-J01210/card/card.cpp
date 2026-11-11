#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500005],sum[500005];
bool vis[500005];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		stack<int> q;
		for(int j=i;j<=n;j++){
			if(vis[a[j]]==false){
				vis[a[j]]=true;
				q.push(a[j]);
			}else{
				while(1){
					int u=q.top();
					q.pop();
					if(u==a[j]){
						q.push(u);
						break;
					}
					vis[u]=false;
				}
			}
		}
		for(int j=1;j<=n;j++){
			if(vis[j]==true){
				sum[j]++;
			}
			vis[j]=false;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<sum[i]<<" ";
	}
	return 0;
}