#include<bits/stdc++.h>
using namespace std;
int a[200009],cnt[100009];
vector<int>g;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		g={};
		for(int j=i;j<=n;j++){
			for(auto k:g){
				if(g[k]==a[j]){
					for(int p=k;p<=n;p++){
						g.erase(k,g.end());
					}
					g[k]=a[j];
				}else{
					g.push_back(a[j]);
				}
			}	
		}
		for(int j=0;j<g.size();j++){
			cnt[g[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[m]<<' ';
	}
	return 0;
}
