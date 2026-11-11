#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[10050],k,k1[10050],k2[10050],x[100050],y[100050],vis[10050],cnt=0,a[10050];
vector<int> ve[10050];
void dfs(int b,int c,int maxx){
	if(vis[c]==1){
		return;
	}
	if(c==b){
		cnt=maxx;
		return;
	}
	vis[c]=1;
	for(int i=0;i<ve[c].size();i++){
		dfs(b,ve[c][i],maxx+w[ve[c][i]]+a[ve[c][i]]);
	}
	return; 
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin >>w[i];
    }
	for(int i=1;i<=n;i++){
		cin >>k;
		for(int j=1;j<=k;j++){
			cin >>k1[i]>>k2[i];
			a[k1[i]]=k2[i];
			ve[k1[i]].push_back(k1[i-1]);
			ve[k1[i-1]].push_back(k1[i]);
		}
	} 
	for(int i=1;i<=q;i++){
		cin >>x[i]>>y[i];
		dfs(y[i],x[i],0);
		cout <<cnt;
	}
	
	return 0;
}
