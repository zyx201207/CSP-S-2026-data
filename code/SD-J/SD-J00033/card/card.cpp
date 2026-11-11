#include<bits/stdc++.h>
using namespace std;
bool vis[5005];
int a[5005],cnt[5005];
int main(){
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
		stack<int> s;
		memset(vis,0,sizeof(vis));
		for(int j=i;j<=n;j++){
			if(vis[a[j]]){
				while((s.top()!=a[j])&&(!s.empty())){
					vis[s.top()]=0;
					s.pop();
					
				}
			}
			else{
				s.push(a[j]);
				vis[a[j]]=1;
			}
		}
		while(!s.empty()){
			int t=s.top();
			s.pop();
			cnt[t]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
} 
