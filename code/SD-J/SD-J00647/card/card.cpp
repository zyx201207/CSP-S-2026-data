#include<bits/stdc++.h>
using namespace std;
int a[500005];
stack<int>s;
bool vis[300005];
int ans[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(!vis[a[j]]){
				s.push(a[j]);
				vis[a[j]]=1;
			}else{
				while(s.size()){
					if(s.top()==a[j])break;
					vis[s.top()]=0;
					s.pop();
				}
			}
		}
		while(s.size()){
			ans[s.top()]++;
			s.pop();
		}
		memset(vis,0,sizeof(vis));
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
}
