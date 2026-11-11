#include<bits/stdc++.h>
using namespace std;
int n,m,a[510000],v[510000],c[510000],maxn;
vector<int>x[510000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(v[a[j]]==1){
				while(1){
					if(x[i][x[i].size()-1]==a[j]){
						x[i].pop_back();
						break;
					}
					v[x[i][x[i].size()-1]]=0;
					x[i].pop_back();
				}
			}
			x[i].push_back(a[j]);
			v[a[j]]=1;
		}
		for(int j=0;j<x[i].size();j++){
			c[x[i][j]]++;
			v[x[i][j]]=0;
		}
	}
	for(int i=1;i<=m;i++)cout<<c[i]<<' ';
}
  