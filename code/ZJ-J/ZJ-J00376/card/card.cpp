#include<bits/stdc++.h>
using namespace std;

int n,m,a[500010],cnt[300010],vis[300010];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n>5000){
		for(int i=n;i>=1;i--){
			if(!vis[a[i]]) vis[a[i]]=1,cnt[a[i]]=i;
		}
		for(int i=1;i<=m;i++) cout<<cnt[i]<<" ";
		return 0;
	}
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof vis);
		stack<int> s;
		for(int j=i;j<=n;j++){
			if(!vis[a[j]]) s.push(a[j]),vis[a[j]]=1;
			else{
				while(!s.empty() && s.top()!=a[j]){
					vis[s.top()]=0;
					s.pop();
				}
			}
		}
		while(!s.empty()) cnt[s.top()]++,s.pop();
	}
	for(int i=1;i<=m;i++) cout<<cnt[i]<<" ";
	return 0;
}
