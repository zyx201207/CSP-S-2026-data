#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10,M=3e5+10;
int n,m,a[N],ne[N],ans[M];
vector <int> g[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		g[a[i]].push_back(i);
		ne[i]=i+1;
	}
	for(int i=1;i<=m;i++){
		int nex=ne[g[i].back()],sz=g[i].size();
		sz--;
		for(int j=0;j<sz;j++){
			ne[g[i][j]]=nex;
		}
	}
	for(int i=1;i<=n;i++){
		int t=i;
		while(t<=n){
			ans[a[t]]++;
			t=ne[t];
		}
	}
	m--;
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	cout<<ans[m+1];
	return 0;
} 
