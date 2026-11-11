#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500010];
bool vis[300010];
int ans[300010];
stack <int> s;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(vis[a[j]]==0){
				s.push(a[j]);
				vis[a[j]]=1;
			}
			else{
				while(s.top()!=a[j]){
					vis[s.top()]=0;
					s.pop();
				}
			}
		}
		while(!s.empty()){
			vis[s.top()]=0;
			ans[s.top()]++;
			s.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
