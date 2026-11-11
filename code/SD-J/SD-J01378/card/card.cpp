#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500009],lst[500009],b[500009],d[500009],e[500009],f[500009];
vector<int> v[500009];
queue<int> q;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=n;i>=1;i--){
		//cout<<lst[a[i]]<<'\n';
		if(!lst[a[i]]){
			if(i!=n) v[i].push_back(i+1),d[i+1]++;
			lst[a[i]]=i;
		}else{
			v[i].push_back(lst[a[i]]);
			d[lst[a[i]]]++;
			lst[a[i]]=i;
		}
	}
	for(int i=1;i<=n;i++){
		if(!d[i]) q.push(i);
		f[i]=1;
	}
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int i=0;i<v[u].size();i++){
			d[v[u][i]]--;
			if(d[v[u][i]]==0){
				q.push(v[u][i]);
				
			}f[v[u][i]]+=f[u];
		}
	}
	for(int i=1;i<=n;i++) e[a[i]]=max(e[a[i]],f[i]);
	for(int i=1;i<=m;i++) cout<<e[i]<<' ';
	
	
	
	
	return 0;
}
/*
³æÐè
ÔÆÁ¦
°×É×
³æÇÒ 
*/ 
