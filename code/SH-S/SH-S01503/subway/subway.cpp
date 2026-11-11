#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int c,n,m,d,q;
vector<ll> w;
vector<vector<int> > nei;
vector<vector<ll> > a,t,ans;
vector<bool> used;
void dfs(int curr){
	for(int i=0;i<m;i++){
		if(nei[curr][i]!=-1){
			if(nei[curr][i]=0){
				ans[curr][i]=0; 
			}else{
				if(ans[cu])
			}
		}
	}
}
int main(){
	//freopen("subway.in","r",stdin);
	//freopen("subeay.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	w.resize(m+1,0);
	for(int i=0;i<m;i++){
		cin>>w[i];
	}
	nei.resize(m+1);
	used.resize(m+1,false)
	for(int i=0;i<m;i++){
		nei[i].resize(m+1,-1);
		nei[i][i]=0;
	}
	a.resize(n+1);
	k.resize(n+1);
	for(int i=0;i<n;i++){
		int k;
		cin>>k;
		a[i].resize(k+1,0);
		k[i].resize(k+1,0);
		for(int j=0;j<k;j++){
			cin>>a[i][j]>>t[i][j];
		}
		for(int j=0;j<k;j++){
			for(int l=j+1;l<k;l++){
				nei[a[i][j]][a[i][l]]=i+1;
				nei[a[i][l]][a[i][j]]=i+1;
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		
	}
	return 0;
} 
