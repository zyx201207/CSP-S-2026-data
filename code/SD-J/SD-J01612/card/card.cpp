#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
long long n,m;
const int N=500005,M=300005;
long long a[N],ans[M];
bool vis[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	stack<int> sta;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		while(!sta.empty()){
			sta.pop();
		}
		memset(vis,0,sizeof(vis));
		for(int j=i;j<=n;j++){
			if(!vis[a[j]]){
				sta.push(a[j]);
				vis[a[j]]=1;
			}
			else{
				while(sta.top()!=a[j]&&!sta.empty()){
					vis[sta.top()]=0;
					sta.pop();
				}
			}
		}
		for(int j=1;j<=m;j++){
			if(vis[j]){
				ans[j]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
} 
