#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,i,j,k,f[500100],q[500100],a[500100];
vector<int>v[500100];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++)
		cin>>a[i];
	for(i=1;i<=n;i++)
		v[a[i]].push_back(i);
	for(i=1;i<=m;i++){
		for(j=0;j<v[i].size()-1;j++){
			f[v[i][j]]=v[i][j+1];
		}
	}
	
	for(i=1;i<=n;i++){
		k=i;
		while(k<=n){
			while(f[k]) k=f[k];
			q[a[k]]++;
			k++;
		}
	}
	for(i=1;i<=m;i++) cout<<q[i]<<" ";
	return 0;
}

