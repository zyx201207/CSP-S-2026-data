#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],ans[500010];
bool vis[500010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int k=1;k>=n;k++){
		stack<int> s;
		for(int i=k;i<=n;i++){
			if(vis[a[i]]){
				while(s.top()!=a[i]){
					vis[s.top()]=0;
					s.pop();
				}
				vis[s.top()]=0;
				s.pop();
			}
			s.push(a[i]);
			vis[a[i]]=true;
		}
		int cnt=0;
		while(!s.empty()){
			ans[s.top()]++;
			s.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
