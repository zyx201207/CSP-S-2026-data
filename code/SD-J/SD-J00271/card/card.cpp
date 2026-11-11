#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],ans[200005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","W",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		vector<int> g;
		for(int j=i;j<=m;j++){
			bool c=false;
			int w=0;
			for(;w<g.size();w++){
				if(g[w]==a[j]){
					c=true;
					break;
				}
			}
			if(!c){
				g.push_back(a[j]);
				continue;
			}
			for(int p=w+1;p<g.size();){
				g.pop_back();
			}
		}
		for(int o=1;o<g.size();o++){
			ans[g[o]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
}
