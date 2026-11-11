#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500010];
int ans[300010];
bool vis[300010];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof(vis));
		stack<int> p;
		for(int j=i;j<=n;j++){
			if(vis[a[j]]==1){
				while(1){
					if(p.top()==a[j]){
						break;
					}
					int jmc=p.top();
					p.pop();
					vis[jmc]=0;
				}
			}else{
				p.push(a[j]);
				vis[a[j]]=1;
			}
			
		}
		while(!p.empty()){
			ans[p.top()]++;
			p.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
    return 0;
}

