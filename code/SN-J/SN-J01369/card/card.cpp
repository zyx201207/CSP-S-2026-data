#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	int m;
	cin>>m;
	vector<int> z;
	vector<int> p;
	int ans[m+1]={};
	for(int i=1;i<=n;i++){
		int y;
		cin>>y;
		p.push_back(y);
	}
	for(int i=1;i<=n;i++){
		int zb=1;
		for(int j=i;j<=n;j++){
			z.push_back(p[j]);
			for(int k=z.size()-1;k>=zb;k--){
				if(z[j]==z[k]){
					zb=j;
				}
			}
		}
		for(int l=zb;l<=z.size();l++){
			int t=z[l];
			ans[t]+=1;
		}
		for(int x=0;x<z.size();x++){
			z[x]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i];
	}
	return 0;
}
