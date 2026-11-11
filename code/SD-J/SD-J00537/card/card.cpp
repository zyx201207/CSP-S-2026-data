#include<bits/stdc++.h>
using namespace std;
int v[500010];
int d[300010];
int p[500010];
int ans[300010];
int main(){
	ios::sync_with_stdio(nullptr);
	cin.tie(false);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>v[i];
		if(d[v[i]]!=0){
			p[d[v[i]]]=i;
		}
		d[v[i]]=i;
	}
	for(int i=1;i<=n;i++){
		int x=i;
		while(x<=n){
			if(p[x]!=0){
				x=p[x];
			}else{
				ans[v[x]]++;
				x++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0; 
} 
