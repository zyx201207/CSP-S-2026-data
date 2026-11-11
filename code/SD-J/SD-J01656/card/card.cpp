#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
const int M=3e5+5;
int a[N],vis[M],b[M]; 
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	queue<int> q;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	for(int i=1;i<=n;i++){
		
		for(int j=i;j<=n;j++){
			if(vis[a[j]]==0){
				q.push(a[j]);
				vis[a[j]]=1;
				
			}else{
				while(!q.empty()){
					q.pop();
					memset(vis,0,sizeof(vis));
				}
				vis[a[j]]=1;
				q.push(a[j]);
				
			}
		}
		while(!q.empty()){
		int o=q.front();
			b[o]++;
			q.pop();
		}
		memset(vis,0,sizeof(vis));
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<"\n";
	}
	return 0;
}

