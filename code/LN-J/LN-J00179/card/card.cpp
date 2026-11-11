#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[5005],vis[5005][3005],ans[3005];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		stack<int> s;
		for(int j=i;j<=n;j++){
			if(vis[i][a[j]])while(true){
				if(s.top()==a[j]){
					s.pop();break;
				}
				vis[i][s.top()]=0;s.pop();
			}
			vis[i][a[j]]=1;s.push(a[j]);
		}
		for(int j=1;j<=m;j++)
			ans[j]+=vis[i][j];
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<' ';
	cout<<'\n';
	return 0;
}
