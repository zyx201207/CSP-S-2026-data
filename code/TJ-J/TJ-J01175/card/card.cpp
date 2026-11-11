#include<bits/stdc++.h>
using namespace std;
int n,m,vis,sum;
int a[500010];
int las[500010];
vector<int> f[500010];
int vi[500010];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(f[a[i]].size()!=0){
			if(f[a[i]].size()%2==1){
				las[i]=f[a[i]][f[a[i]].size()-1];
			}
			else{
				las[i]=0;
			}
		}else{
			las[i]=0;
		}
		f[a[i]].push_back(i);
	}
	for(int i=1;i<=n;i++){
		vis=0;
		for(int j=n;j>i;j--){
			if(las[j]>=i){
				vis=1;
				for(int u=j;u<=n;u++){
					vi[a[u]]++;
				} 
			}
		} 
		if(vis==0){
			for(int u=i;u<=n;u++){
				vi[a[u]]++;
			} 
		}
	}
	for(int i=1;i<=m;i++){
		cout<<vi[i]<<" ";
	}
	return 0;
}
