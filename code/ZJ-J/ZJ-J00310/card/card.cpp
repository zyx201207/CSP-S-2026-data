#include <bits/stdc++.h>
using namespace std;
queue<int> q;
int n,m,a[10005],vis[10005],ans[10005];
int main(){
	//freopen("card1.in","r",stdin);
	//freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		vis[a[i]]++;
	}
	for(int i=1;i<=n;i++){
		long long x=n-i+1;
		for(int j=x;j<=n;j++){
				q.push(a[j]);
		}
		while(x>0){
			int t=q.front();
			if(vis[t]>1){
				vis[t]++;
				q.push(t);
				long long s=q.size()-1;
				while(s--){
					q.pop();	
				}
			}else{
				q.push(t);
				vis[t]++;
			}
		}
		while(q.size()>0){
			int t=q.front();
			ans[t]++;
			q.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
